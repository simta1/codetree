#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> getLpf(int n) {
    vector<int> primes, lpf(n + 1); // least prime factor // O(N)
    for (int i = 2; i <= n; i++) {
        if (!lpf[i]) {
            lpf[i] = i;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i > n / p) break;
            lpf[i * p] = p;
            if (i % p == 0) break;
        }
    }
    return lpf;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    auto lpf = getLpf(1e6);
    auto isp = [&](int n) {
        n = abs(n);
        if (n == 1) return false;
        return lpf[n] == n;
    };

    int TC;
    for (cin >> TC; TC--;) {
        int n, m;
        cin >> n >> m;
        // n = rand() % 100 + 1;
        // // m = rand() % 100 + 1;
        // m = 4;
        // cout << n << " " << m << "::\n";

        if (m == 4) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ++cur << " ";
                }
                cout << "\n";
            }
            continue;
        }

        vector v(n, vector<int>(m));
        auto &a = v[0];
        a[0] = 1;
        for (int j = 1; j < m; j++) {
            a[j] = a[j - 1] + 2 * n;
            if (a[j] > n * m) a[j] = 1 + n;
        }

        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) v[i][j] = v[i - 1][j] + 1;
        }

        for (auto &r : v) {
            for (auto &e : r) cout << e << " ";
            cout << "\n";
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 1; j < m; j++) {
        //         assert(!isp(v[i][j] - v[i][j - 1]));
        //     }
        // }
        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         assert(!isp(v[i - 1][j] - v[i][j]));
        //     }
        // }

    }

    return 0;
}
