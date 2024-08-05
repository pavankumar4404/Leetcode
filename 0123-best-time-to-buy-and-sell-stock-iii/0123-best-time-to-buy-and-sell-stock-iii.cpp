class Solution {
    // 0 - Buy, 1 - sell, 2 - buy, 3 - sell
    int solve(int i, int transactions, vector<int> &prices, vector<vector<int>> &dp){
        if(transactions == 4) return 0;
        if(i == prices.size()) return 0;

        if(dp[i][transactions] != -1) return dp[i][transactions];

        int profit = 0;
        if(transactions % 2 == 0){
            profit = max(-prices[i] + solve(i+1, transactions + 1, prices, dp), solve(i+1, transactions, prices, dp));
        }
        else{
            profit = max(prices[i] + solve(i+1, transactions + 1, prices, dp), solve(i+1, transactions, prices, dp));
        }
        return dp[i][transactions] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(0, 0, prices, dp);
    }
};