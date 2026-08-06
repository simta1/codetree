#include <bits/stdc++.h>
using namespace std;
using ll = long long;

tuple<ll, ll, ll> egcd(ll a, ll b) { // ax + by = gcd(a, b)
    if (b == 0) return {1, 0, a};
    auto [x, y, g] = egcd(b, a % b);
    return {y, x - (a / b) * y, g};
}
ll modInv(ll a, ll b) {
    auto [x, y, g] = egcd(a, b);
    return g != 1 ? -1 : (x + b) % b;
} // modInv(n, MOD)

ll binpow(ll a, ll n, ll mod) { // a ^ n % mod
    ll res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    constexpr ll MOD = 1e9 + 7;

    int TC;
    for (cin >> TC; TC--;) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> v(n);
        for (auto &e : v) cin >> e;

        // vector<ll> dp(n + 1);
        // dp[0] = 1;
        // for (int _ = m; _--;) {
        //     vector<ll> ndp(n + 1);
        //     ndp[0] = dp[0] * (k - 1) % MOD;
        //     for (int i = 1; i < n; i++) {
        //         ndp[i] = (dp[i] * (k - 1) + dp[i - 1]) % MOD;
        //     }
        //     ndp[n] = (dp[n] * k + dp[n - 1]) % MOD;
        //     swap(dp, ndp);
        // }
        // cout << dp[n] << "\n";

        // vector a(n, vector<int>(n));
        // for (int i = 0; i < n; i++) {
        //     a[i][i] = k - 1;
        //     a[i + 1][i] = 1;
        // }
        // a[n][n] = k;

        ll tot = binpow(k, m, MOD);

        ll pw = binpow(k - 1, m, MOD);
        ll mCi = 1; // i=0
        ll sum = mCi * pw % MOD;
        // cout << mCi << " " << pw << "\n";

        ll inv = modInv(k - 1, MOD);

        for (int i = 1; i < n; i++) {
        // cout << mCi << " " << pw << "\n";
            mCi = mCi * (m - i + 1) % MOD * modInv(i, MOD) % MOD;
            pw = pw * inv % MOD;
            sum += mCi * pw;
            sum %= MOD;
        }

        tot -= sum;
        if (tot < 0) tot += MOD;
        cout << tot << "\n";




    }

    return 0;
}
