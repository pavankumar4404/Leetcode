class Solution {
    // int solve(int i, int buy, vector<int>& prices, vector<vector<int>> &dp){
    //     if(i == prices.size()) return 0;
    //     if(dp[i][buy] != -1) return dp[i][buy];
    //     if(buy == 1){
    //         return dp[i][buy] = max(-prices[i] + solve(i+1, 0, prices, dp),      //buy
    //                     solve(i+1, 1, prices, dp));                 //don't buy
    //     }
    //     else {
    //         return dp[i][buy] = max(prices[i] + solve(i+1, 1, prices, dp),       //sell
    //                     solve(i+1, 0, prices, dp));                 //don't sell
    //     }
    // }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solve(0, 1, prices, dp);

        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // for(int i=n-1; i>=0; i--){
        //     for(int buy=0; buy<=1; buy++){
        //         if(buy == 1){
        //             dp[i][buy] = max(-prices[i] + dp[i+1][0],      //buy
        //                             dp[i+1][1]);                   //don't buy
        //         }
        //         else {
        //             dp[i][buy] = max(prices[i] + dp[i+1][1],       //sell
        //                             dp[i+1][0]);                   //don't sell
        //         }
        //     }
        // }
        // return dp[0][1];


        // vector<int> next(2, 0), cur(2,0);
        // for(int i=n-1; i>=0; i--){
        //     for(int buy=0; buy<=1; buy++){
        //         if(buy == 1){
        //             cur[buy] = max(-prices[i] + next[0],      //buy
        //                             next[1]);                 //don't buy
        //         }
        //         else {
        //             cur[buy] = max(prices[i] + next[1],       //sell
        //                             next[0]);              //don't sell
        //         }
        //     }
        //     next = cur;
        // }
        // return cur[1];

        // greedy
        int ans = 0;
        for(int i=1; i<n; i++){
            if(prices[i] >= prices[i-1]) ans += prices[i]-prices[i-1];
        }
        return ans;
    }
};