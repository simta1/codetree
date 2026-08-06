#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    if (n & 1) {
        while (q--) cout << "NO\n";
        return 0;
    }

    string st;
    cin >> st;

    set<int> s;
    for (int i = 0; i < n; i++) {
        if (st[i] != "()"[i & 1]) s.insert(i);
    }

    set<int> l, r;
    for (int i = 0; i < n - 1; i++) {
        if (st[i] == '(' && st[i + 1] == '(') l.insert(i);
        else if (st[i] == ')' && st[i + 1] == ')') r.insert(i);
    }

    while (q--) {
        int i;
        cin >> i;
        --i;
        if (st[i] != "()"[i & 1]) s.erase(i);
        else s.insert(i);

        if (i) { // i-1, i
            if (st[i - 1] == '(' && st[i] == '(') l.erase(i - 1);
            if (st[i - 1] == ')' && st[i] == ')') r.erase(i - 1);
        }
        if (i + 1 < n) { // i, i+1
            if (st[i + 1] == '(' && st[i] == '(') l.erase(i);
            if (st[i + 1] == ')' && st[i] == ')') r.erase(i);
        }

        st[i] = "()"[st[i] == '('];

        if (i) { // i-1, i
            if (st[i - 1] == '(' && st[i] == '(') l.insert(i - 1);
            if (st[i - 1] == ')' && st[i] == ')') r.insert(i - 1);
        }
        if (i + 1 < n) { // i, i+1
            if (st[i + 1] == '(' && st[i] == '(') l.insert(i);
            if (st[i + 1] == ')' && st[i] == ')') r.insert(i);
        }

        if ([&]() {
            if (st[0] == ')' || st.back() == '(') return false;
            if (s.empty()) return true;
            if (l.empty() || r.empty()) return false;
            int first = *l.begin();
            int last = *prev(r.end()) + 1;
            int i1 = *s.begin(), i2 = *prev(s.end());
            return first <= i1 && i2 <= last;
        }()) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
