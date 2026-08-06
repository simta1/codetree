#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int TC;
    for (cin >> TC; TC--;) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &e : v) cin >> e;

        int mn = *min_element(v.begin(), v.end());
        int mx = *max_element(v.begin(), v.end());
        if (mn < 0) cout << mn << "\n";
        else cout << mx << "\n";
    }

    return 0;
}
