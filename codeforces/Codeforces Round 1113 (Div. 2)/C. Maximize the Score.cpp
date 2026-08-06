#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline ll sq(ll x) {
    return x * x;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int TC;
    for (cin >> TC; TC--;) {
        int n;
        cin >> n;

        vector<int> v(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++) cin >> v[i];

        vector<int> last(n + 1);
        vector<ll> dp(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++) {
            dp[i] = dp[i - 1] + 1;
            if (last[v[i]]) dp[i] = max(dp[i], dp[last[v[i]] - 1] + sq(i - last[v[i]] + 1));
            last[v[i]] = i;
        }

        cout << dp[2 * n] << "\n";
    }

    return 0;
}
