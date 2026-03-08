#include <bits/stdc++.h>
 
using namespace std;
 
main() {
#ifndef LOCAL
    freopen("dropin.txt", "r", stdin);
    freopen("dropout.txt", "w", stdout);
#endif LOCAL
    cin.tie(0)->sync_with_stdio(0);
 
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
 
    map<pair<int, int>, int> dp;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[{a[i], a[j]}] = 1 + dp[{a[j], 2 * a[j] - a[i]}];
        }
    }
 
    int ans = 0;
    for (auto [k, v] : dp) ans = max(ans, v);
    cout << ans + 1 << '\n';
}