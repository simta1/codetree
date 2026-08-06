#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int TC;
    for (cin >> TC; TC--;) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for (auto &e : a) cin >> e;
        for (auto &e : b) cin >> e;
        // for (auto &e : a) cout << e << " "; cout << "\n";
        // for (auto &e : b) cout << e << " "; cout << "\n";

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if ([&]() {
            if (n < 2 * m) return false;
            int j = 0;
            for (int i = 0; i < m; i++) {
                // if (i == 0) cout << j << "::\n";
                while (j < n && a[j] < b[i]) ++j;
                if (i + 1 > j) return false;
            }
        // for (auto &e : a) cout << e << " "; cout << "\n";
        // for (auto &e : b) cout << e << " "; cout << "\n";
            j = n - 1;
            for (int i = m - 1; i >= 0; i--) {
                // if (i == 1) cout << j << " " << a[j] << " " << b[i] << "::\n";
                while (j >= 0 && a[j] > b[i]) --j;
                // if (i == 1) cout << j << "::\n";
                if (m - i > n - 1 - j) return false;
            }
            return true;
        }()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
