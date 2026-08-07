#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998'244'353;
ll binpow(ll a, ll n) {
    ll res = 1;
    for (; n ; n >>= 1) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    cout << binpow(n, m) * binpow(m, n - 1) % MOD;

    return 0;
}
