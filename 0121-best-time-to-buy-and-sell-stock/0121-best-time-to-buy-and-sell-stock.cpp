class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<int> dp(n, 0);
        // dp[0] = prices[0];
        int buy = prices[0];
        int ans = 0;
        for(int i=1; i<n; i++){
            int cost = prices[i] - buy;
            ans = max(ans, cost);
            buy = min(buy, prices[i]);
        }
        return ans;
    }
};