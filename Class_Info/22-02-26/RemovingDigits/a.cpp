#include <bits/stdc++.h>
using namespace std;
#define arr array
#define vec vector
const int N = 1e6 + 5, INF = 1e9;

int n;
arr<int, N> dp;

vec<int> gt_dgts(int x) {
    vec<int> ans;
    while (x != 0) {
        ans.push_back(x % 10);
        x /= 10;
    }
    return ans;
}

int main() {
    cin >> n;

    dp[0] = 0;
    for (int x = 1; x <= n; x++) {
        dp[x] = INF;
        for (int d : gt_dgts(x)) {
            int y = x - d;
            if (y < 0) continue;
            dp[x] = min(dp[x], 1 + dp[y]);
        }
    }

    int ans = dp[n];
    cout << ans << '\n';
}
