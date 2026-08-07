#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    sort(l.rbegin(), l.rend());
    sort(r.begin(), r.end());

    int cur = n - 1;
    ll ans = 0;
    for (int i = 0; i < n && l[i] > r[i]; i++) {
        ans += ll(l[i] - r[i]) * cur;
        cur -= 2;
    }
    cout << ans;

    return 0;
}
