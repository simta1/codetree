#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <int ALPHA = 3, char FIRST = 'A'>
struct Aho {
    struct Node {
        array<int, ALPHA> mp, go;
        int fail = 0;
        bool end = false;
        Node() {
            mp.fill(-1);
            go.fill(-1);
        }
    };
    vector<Node> tree = {Node()};
    int charToIdx(char ch) { return ch - FIRST; }
    void insert(const string &st) {
        int cur = 0;
        for (auto ch : st) {
            int i = charToIdx(ch);
            if (!~tree[cur].mp[i]) {
                tree[cur].mp[i] = tree.size();
                tree.emplace_back();
            }
            cur = tree[cur].mp[i];
        }
        tree[cur].end = true;
    }
    void build() {
        queue<int> q;
        for (int i = 0; i < ALPHA; i++) {
            int nxt = tree[0].mp[i];
            if (!~nxt) tree[0].go[i] = 0;
            else {
                tree[0].go[i] = nxt;
                q.push(nxt);
            }
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            tree[cur].end |= tree[tree[cur].fail].end;
            for (int i = 0; i < ALPHA; i++) {
                int nxt = tree[cur].mp[i];
                if (!~nxt) tree[cur].go[i] = tree[tree[cur].fail].go[i];
                else {
                    tree[cur].go[i] = nxt;
                    tree[nxt].fail = tree[tree[cur].fail].go[i];
                    q.push(nxt);
                }
            }
        }
    }
    vector<int> dp;
    int dfs(int cur) {
        if (tree[cur].end) return 0;

        auto &res = dp[cur];
        if (res == -2) {
            cout << "A+";
            exit(0);
        }
        if (~res) return res;

        res = -2;
        int mx = 0;
        for (int i = 0; i < ALPHA; i++) {
            int nxt = tree[cur].go[i];
            mx = max(mx, dfs(nxt));
        }
        return res = mx + 1;
    }
    void f() {
        dp.resize(tree.size(), -1);
        int len = dfs(0) - 1;
        if (!len) {
            cout << "F";
            exit(0);
        }
        int cur = 0;
        string ans;
        while (ans.size() < len) {
            for (int i = 0; i < ALPHA; i++) {
                int nxt = tree[cur].go[i];
                if (dp[nxt] + 1 == dp[cur]) {
                    ans += char(FIRST + i);
                    cur = nxt;
                    break;
                }
            }
        }
        cout << ans;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    Aho aho;

    for (int i = 0; i < n; i++) {
        string st;
        cin >> st;
        aho.insert(st);
    }

    aho.build();

    aho.f();

    return 0;
}