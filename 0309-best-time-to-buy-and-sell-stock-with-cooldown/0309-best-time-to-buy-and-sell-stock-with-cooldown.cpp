class Solution {
    int solve(int i, int buy, vector<int>& prices, vector<vector<int>> &dp){
        if(i >= prices.size()) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 1){
            return dp[i][buy] = max(-prices[i] + solve(i+1, 0, prices, dp),      //buy
                        solve(i+1, 1, prices, dp));                 //don't buy
        }
        else {
            return dp[i][buy] = max(prices[i] + solve(i+2, 1, prices, dp),       //sell
                        solve(i+1, 0, prices, dp));                 //don't sell
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};