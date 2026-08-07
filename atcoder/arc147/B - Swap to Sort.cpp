#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<pair<char, int>> ans;
    int cnt = 0;
    int tidx = 1;
    for (int i = 1; i <= n; i += 2) {
        if (~v[i] & 1) {
            int idx = i;
            while (idx > tidx) {
                ans.emplace_back('B', idx - 2);
                swap(v[idx - 2], v[idx]);
                idx -= 2;
            }
            ++cnt;
            tidx += 2;
        }
    }

    tidx = 2;
    int cnt2 = 0;
    for (int i = 2; i <= n; i += 2) {
        if (v[i] & 1) {
            int idx = i;
            while (idx > tidx) {
                ans.emplace_back('B', idx - 2);
                swap(v[idx - 2], v[idx]);
                idx -= 2;
            }
            ++cnt2;
            tidx += 2;
        }
    }
    assert(cnt == cnt2);

    for (int i = 2; i <= 2 * cnt; i += 2) {
        ans.emplace_back('A', i - 1);
        swap(v[i - 1], v[i]);
    }

    for (int i = 1; i <= n; i++) {
        int mnidx = i;
        for (int j = i + 2; j <= n; j += 2) {
            if (v[mnidx] > v[j]) mnidx = j;
        }
        assert(v[mnidx] == i);

        while (mnidx > i) {
            ans.emplace_back('B', mnidx - 2);
            swap(v[mnidx], v[mnidx - 2]);
            mnidx -= 2;
        }
    }

    assert(is_sorted(v.begin(), v.end()));
    assert(ans.size() <= 100'000);
    cout << ans.size() << "\n";
    for (auto [a, b] : ans) cout << a << " " << b << "\n";

    return 0;
}
