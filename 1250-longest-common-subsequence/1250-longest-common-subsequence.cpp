class Solution {
    // int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    //     if(i < 0 || j < 0){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s1[i] == s2[j]) return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
    //     int pick1 = solve(i-1, j, s1, s2, dp);
    //     int pick2 = solve(i, j-1, s1, s2, dp);

    //     return dp[i][j] = max(pick1, pick2);
    // }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n-1, m-1, text1, text2, dp);

        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=m; j++){
        //         if(text1[i-1] == text2[j-1]){
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //         }
        //     }
        // }
        // return dp[n][m];

        vector<int> dp(m+1, 0), cur(m+1, 0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    cur[j] = 1 + dp[j-1];
                }
                else{
                    cur[j] = max(dp[j], cur[j-1]);
                }
            }
            dp = cur;
        }
        return dp[m];
    }
};