#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int TC;
    for (cin >> TC; TC--;) {
        int n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;

        vector pfs(4, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            int x = a[i] - '0';
            int y = b[i] - '0';
            ++pfs[x << 1 | y][i + 1];
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= n; j++) pfs[i][j] += pfs[i][j - 1];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;

            int c00 = pfs[0][r] - pfs[0][l - 1];
            int c01 = pfs[1][r] - pfs[1][l - 1];
            int c10 = pfs[2][r] - pfs[2][l - 1];
            int c11 = pfs[3][r] - pfs[3][l - 1];
            int need = abs(c01 - c10);
            if (need <= c00 + c11) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
