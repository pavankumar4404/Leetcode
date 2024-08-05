class Solution {
    // 0 - Buy, 1 - sell, 2 - buy, 3 - sell
    // int solve(int i, int transactions, int k, vector<int> &prices, vector<vector<int>> &dp){
    //     if(transactions == 2*k) return 0;
    //     if(i == prices.size()) return 0;

    //     if(dp[i][transactions] != -1) return dp[i][transactions];

    //     int profit = 0;
    //     if(transactions % 2 == 0){
    //         profit = max(-prices[i] + solve(i+1, transactions + 1, k, prices, dp), solve(i+1, transactions, k, prices, dp));
    //     }
    //     else{
    //         profit = max(prices[i] + solve(i+1, transactions + 1, k, prices, dp), solve(i+1, transactions, k, prices, dp));
    //     }
    //     return dp[i][transactions] = profit;
    // }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2*k, -1));
        // return solve(0, 0, k, prices, dp);

        // vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));
        // for(int i = n-1; i >= 0; i--){
        //     for(int transactions = 0; transactions < 2*k; transactions++){
        //         int profit = 0;
        //         if(transactions % 2 == 0){
        //             profit = max(-prices[i] + dp[i+1][transactions + 1], dp[i+1][transactions]);
        //         }
        //         else{
        //             profit = max(prices[i] + dp[i+1][transactions + 1], dp[i+1][transactions]);
        //         }
        //         dp[i][transactions] = profit;
        //     }
        // }
        // return dp[0][0];

        vector<int> dp(2*k+1, 0), cur(2*k+1, 0);
        for(int i = n-1; i >= 0; i--){
            for(int transactions = 0; transactions < 2*k; transactions++){
                int profit = 0;
                if(transactions % 2 == 0){
                    profit = max(-prices[i] + dp[transactions + 1], dp[transactions]);
                }
                else{
                    profit = max(prices[i] + dp[transactions + 1], dp[transactions]);
                }
                cur[transactions] = profit;
            }
            dp = cur;
        }
        return dp[0];
    }
};