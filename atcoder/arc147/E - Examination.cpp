#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> ts;
    map<int, int> mp;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int ans = n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ts.push_back(a);
        ts.push_back(b);
        if (a >= b) pq.emplace(b, a);
        else { // a < b
            --mp[a];
            ++mp[b];
            --ans;
        }
    }

    sort(ts.begin(), ts.end());
    ts.erase(unique(ts.begin(), ts.end()), ts.end());
    int cur = 0;
    priority_queue<int> as;
    for (auto t : ts) {
        if (mp.count(t)) cur += mp[t];
        if (cur < 0) {
            while (!pq.empty() && pq.top().first <= t) {
                auto [b, a] = pq.top();
                pq.pop();
                as.push(a);
            }
            while (cur < 0 && !as.empty() && as.top() > t) {
                ++cur;
                --mp[as.top()];
                as.pop();
                --ans;
            }
            if (cur < 0) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
