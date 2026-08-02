#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (auto &e : v) cin >> e;

    auto check = [&](int mx) {
        bitset<30'005> bs;
        bs[0] = 1;
        for (auto e : v) {
            for (int i = mx; i; i >>= 1) bs |= bs << e * (i + 1 >> 1);
        }
        return bs[m];
    };

    int lo = 0, hi = m + 1;
    while (lo + 1 < hi) {
        int mid = lo + hi >> 1;
        if (check(mid)) hi = mid;
        else lo = mid;
    }

    if (hi == m + 1) cout << -1;
    else cout << hi;

    return 0;
}