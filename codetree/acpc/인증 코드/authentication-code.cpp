#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int qry(vector<int> basis, int a, int b) {
    sort(basis.rbegin(), basis.rend());
    for (int i = 1; i < basis.size(); i++) {
        int bit = 1 << __lg(basis[i]);
        for (int j = 0; j < i; j++) {
            if (basis[j] & bit) basis[j] ^= basis[i];
        }
    }
    int mx = 0;
    for (auto e : basis) {
        if ((mx ^ e) <= b) mx ^= e;
    }
    return mx >= a ? mx : -1;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> ws(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v >> ws[i].second;
        ws[i].first = 0;
    }

    int N = q + 1;
    int sz = 1;
    while (sz < N) sz <<= 1;
    vector<vector<int>> tree(sz << 1);
    auto upd = [&](int l, int r, int w) {
        for (l |= sz, r |= sz; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) tree[l++].push_back(w);
            if (~r & 1) tree[r--].push_back(w);
        }
    };

    vector<pair<int, int>> qs(q + 1, {-1, -1});
    for (int t = 1; t <= q; t++) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            qs[t] = {a, b};
        }
        else {
            int i, w;
            cin >> i >> w;
            upd(ws[i].first, t - 1, ws[i].second);
            ws[i].first = t;
            ws[i].second = w;
        }
    }
    for (int i = 1; i < n; i++) upd(ws[i].first, q, ws[i].second);

    vector<int> basis;
    auto insert = [&](int x) {
        for (auto e : basis) x = min(x, x ^ e);
        if (x) basis.push_back(x);
    };

    auto dfs = [&](auto &&dfs, int node, int s, int e) {
        if (q < s) return;
        int sz = basis.size();
        for (auto e : tree[node]) insert(e);
        if (s == e) {
            auto [a, b] = qs[s];
            if (~a) cout << qry(basis, a, b) << "\n";
        }
        else {
            int m = s + e >> 1;
            dfs(dfs, node << 1, s, m);
            dfs(dfs, node << 1 | 1, m + 1, e);
        }
        basis.resize(sz);
    };
    dfs(dfs, 1, 0, sz - 1);

    return 0;
}