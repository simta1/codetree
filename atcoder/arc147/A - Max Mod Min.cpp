#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    int ans = 0;
    while (s.size() > 1) {
        int mn = *s.begin(), mx = *prev(s.end());
        s.erase(s.find(mx));
        if (mx % mn) s.insert(mx % mn);
        ++ans;
    }

    cout << ans;

    return 0;
}
