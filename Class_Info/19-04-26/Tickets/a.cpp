/*
dp[i] := min cost to cover travel for days [1, i]
*/

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
 
int dp[10005];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int c1, d1, c2, d2; cin >> c1 >> d1 >> c2 >> d2;
    int n; cin >> n;
    vector<int> days(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    fill(dp, dp + n + 2, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || dp[i-1]) {
            int pos1 = lower_bound(days.begin(), days.end(), days[i] + d1) - days.begin();
            dp[pos1] = min(dp[pos1], dp[i] + c1);
            int pos2 = lower_bound(days.begin(), days.end(), days[i] + d2) - days.begin();
            dp[pos2] = min(dp[pos2], dp[i] + c2);
        }
    }
 
    if (n == 1) cout << min(c1, c2);
    else cout << dp[days.size()];
}