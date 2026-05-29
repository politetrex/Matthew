#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 10000005;
 
int n, mod;
 
int dp[MAX_N][2];
 
int main() {
    freopen("drivein.txt", "r", stdin);
    freopen("driveout.txt", "w", stdout);
 
    cin >> n >> mod; 
 
    dp[0][0] = 1;
    dp[1][0] = 2;
    dp[1][1] = 1;
    for (int x = 2; x <= n; x++) {
        for (int restricted = 0; restricted <= 1; restricted++) {
            int a = dp[x - 1][0], b = dp[x - 2][0], c = dp[x - 1][1];
            
            int way1 = (a * a) % mod;
            int way2 = (((b * b) % mod) * c) % mod;
            
            if (!restricted) dp[x][restricted] = 1 + way1 + way2;
            else dp[x][restricted] = 1 + way2;
            dp[x][restricted] %= mod;
        }
    }
 
    // Mod again for base cases
    cout << dp[n][0] % mod << '\n'; 
     
 
}