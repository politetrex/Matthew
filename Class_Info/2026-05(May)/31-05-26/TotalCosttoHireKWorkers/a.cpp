class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int size) {
        int n = costs.size();
        
        int left = size - 1, right = n - size;
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>, 
                       greater<pair<int, int>>> order;
        
        for (int i = 0; i <= left; i++)
            order.push({costs[i], i});
        for (int i = right; i < n; i++) {
            if (i <= left) continue;
            order.push({costs[i], i
        }

        long long ans = 0;
        for (int _ = 0; _ < k; _++) {
            auto [val, index] = order.top();
            order.pop();

            ans += val;
            if (left + 1 >= right) continue;
            if (index <= left) {
                left++;
                order.push({costs[left], left});
            } else {
                right--;
                order.push({costs[right], right});
            }
        }
        return ans;
    }
};