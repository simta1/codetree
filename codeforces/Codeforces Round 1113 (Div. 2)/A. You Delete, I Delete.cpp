#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int TC;
    for (cin >> TC; TC--;) {
        string st;
        cin >> st;

        int z = 0;
        while (st[z] != '0') ++z;

        int o = 0;
        while (st[o] != '1') ++o;

        for (int i = 0; i < st.size(); i++) {
            if (i != o && i != z) cout << st[i];
        }
        cout << "\n";
    }

    return 0;
}
