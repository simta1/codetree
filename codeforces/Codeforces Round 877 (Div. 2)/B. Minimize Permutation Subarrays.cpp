#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool f(int a, int b, int c) {
    return a < b && b < c;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int TC;
    for (cin >> TC; TC--;) {
        int n;
        cin >> n;

        vector<int> v(n), pos(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            pos[v[i]] = i + 1;
        }

        int p1 = pos[1];
        int p2 = pos[2];
        int pn = pos[n];
        if (f(p1, pn, p2)) cout << "1 1\n";
        else if (f(p2, pn, p1)) cout << "1 1\n";
        else if (f(p1, p2, pn)) cout << p2 << " " << pn << "\n";
        else if (f(p2, p1, pn)) cout << p1 << " " << pn << "\n";
        else if (f(pn, p1, p2)) cout << p1 << " " << pn << "\n";
        else if (f(pn, p2, p1)) cout << p2 << " " << pn << "\n";
    }

    return 0;
}
