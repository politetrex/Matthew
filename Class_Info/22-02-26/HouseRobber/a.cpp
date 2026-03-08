/*
State:
dp[x] := max money we can get by robbing houses [1, x]

Transition:
dp[x] = max(dp[x - 1], m[x] + dp[x - 2])

Base case:
dp[0] = 0
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        const int INF = 1e9;
        vector<int> dp(n + 5, 0);

        dp[0] = 0, dp[1] = nums[0];
        for (int x = 2; x <= n; x++) {
            int leave = dp[x - 1];
            int take = nums[x - 1] + dp[x - 2];
            dp[x] = max(take, leave);
        }   
        return dp[n];
    }
};