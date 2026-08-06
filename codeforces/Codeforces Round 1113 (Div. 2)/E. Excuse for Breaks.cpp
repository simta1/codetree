#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int TC;
    for (cin >> TC; TC--;) {
        ll n, m, d;
        cin >> n >> m >> d;

        vector<ll> p(m), r(m);
        for (int i = 0; i < m; i++) cin >> p[i] >> r[i];

        for (int i = 1; i < m; i++) r[i] += r[i - 1];

        auto f = [&](int len) { // len <= n
            int idx = upper_bound(p.begin(), p.end(), len) - p.begin() - 1;
            if (idx < 0) return 0LL;
            return r[idx];
        };

        bool ans = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int len = p[i] + p[j] + 1;
                ll x = len <= n ? f(len) : r.back() + f(len - n);
                if (r[i] + r[j] > d + x) ans = true;
            }
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
