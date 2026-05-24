class Solution {
private:
    int get_left_ans(const vector<int>& height) {
        int n = height.size();

        int ans = 0, max_height = INT_MIN, r = n - 1;
        for (int l = 0; l < n; l++) {
            if (height[l] <= max_height) continue;
            max_height = height[l];

            while (r >= 0 && height[r] < height[l])
                r--;
            if (r == -1) continue;
            ans = max(ans, height[l] * (r - l));
        }
        return ans;
    }
    int get_right_ans(const vector<int>& height) {
        int n = height.size();

        int ans = 0, max_height = INT_MIN, l = 0;
        for (int r = n - 1; r >= 0; r--) {
            if (height[r] <= max_height) continue;
            max_height = height[r];

            while (l < n && height[l] < height[r])
                l++;
            if (l == n) continue;
            ans = max(ans, height[r] * (r - l));
        }
        return ans;
    }

public:
    int maxArea(vector<int>& height) {        
        int ans = max(get_left_ans(height), get_right_ans(height));
        return ans;
    }
};