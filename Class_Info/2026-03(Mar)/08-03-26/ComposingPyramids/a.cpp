#include <bits/stdc++.h>
using namespace std;
#define arr array
const int N = 1e5 + 5;
 
int n;
arr<int, N> a;
 
arr<int, N> lf_dp, rg_dp;
arr<int, N> lf_prv, rg_prv;
 
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
 
    for (int i = 1; i <= n; i++) {
        int j = lf_prv[a[i] - 1];
        lf_dp[i] = lf_dp[j] + 1; // Ok when j = 0
        lf_prv[a[i]] = i;
    }
 
    for (int i = n; i >= 1; i--) {
        int j = rg_prv[a[i] - 1];
        rg_dp[i] = rg_dp[j] + 1; // Ok when j = 0
        rg_prv[a[i]] = i;
    }
 
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, 2 * min(lf_dp[i], rg_dp[i]) - 1);
    cout << n - ans << '\n';
}