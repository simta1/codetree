#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> p;
    DSU(int n) : p(n) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int a) {
        while (a != p[a]) a = p[a] = p[p[a]];
        return a;
    }
    void merge(int a, int b) {
        p[find(a)] = find(b);
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(m);
    for (auto &[w, u, v] : edges) cin >> u >> v >> w;
    sort(edges.begin(), edges.end());

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<array<int, 3>> unused;
    DSU dsu(n + 1);
    for (auto [w, u, v] : edges) {
        if (dsu.find(u) != dsu.find(v)) {
            dsu.merge(u, v);
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        else unused.push_back({u, v, w});
    }

    vector<int> in(n + 1), out(n + 1);
    int dfsi = 0;
    int lg = __lg(n);
    vector<int> dep(n + 1);
    vector<ll> dist(n + 1);
    vector ac(n + 1, vector<int>(lg + 1));
    auto ett = [&](auto &ett, int cur, int par) -> void {
        in[cur] = ++dfsi;
        for (auto [nxt, w] : adj[cur]) if (nxt != par) {
            dep[nxt] = dep[cur] + 1;
            dist[nxt] = dist[cur] + w;
            ac[nxt][0] = cur;
            for (int i = 1; i <= lg; i++) ac[nxt][i] = ac[ac[nxt][i - 1]][i - 1];
            ett(ett, nxt, cur);
        }
        out[cur] = dfsi;
    };
    ett(ett, 1, -1);

    auto getLCA = [&](int a, int b) {
        if (dep[a] > dep[b]) swap(a, b);
        for (int d = dep[b] - dep[a]; d; d &= d - 1) b = ac[b][__builtin_ctz(d)];
        if (a == b) return a;
        for (int i = lg; i >= 0; i--) if (ac[a][i] != ac[b][i]) {
            a = ac[a][i];
            b = ac[b][i];
        }
        return ac[a][0];
    };

    vector<int> imos(n + 2);
    int gadd = 0;
    auto f = [&](int u, int v, int lca, ll tot, ll x) { // u-v경로상에서 u로부터 거리 x내인 정점들과 가지들 제거
        if (x < dist[u] - dist[lca]) {
            int cur = u;
            for (int i = lg; i >= 0; i--) {
                int nxt = ac[cur][i];
                if (dist[u] - dist[nxt] <= x) cur = nxt;
            }
            ++imos[in[cur]];
            --imos[out[cur] + 1];
        }
        else {
            int cur = v;
            for (int i = lg; i >= 0; i--) {
                int nxt = ac[cur][i];
                if (dist[v] - dist[nxt] < tot - x) cur = nxt;
            }
            ++gadd;
            --imos[in[cur]];
            ++imos[out[cur] + 1];
        }
    };

    for (auto [u, v, w] : unused) {
        int lca = getLCA(u, v);
        ll tot = dist[u] + dist[v] - dist[lca] * 2;
        if (tot <= w) continue;
        ll mx = (tot - w - 1) / 2;
        f(u, v, lca, tot, mx);
        f(v, u, lca, tot, mx);
    }

    bool flag = false;
    for (int i = 1; i <= n; i++) imos[i] += imos[i - 1];
    for (int i = 1; i <= n; i++) {
        if (gadd + imos[in[i]] == 0) {
            cout << i << " ";
            flag = true;
        }
    }
    if (!flag) cout << "-1";

    return 0;
}
