class Solution {
    // int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
    //     if (j < 0)
    //         return i + 1;
    //     if (i < 0)
    //         return j + 1;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     if (s1[i] == s2[j]) {
    //         return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
    //     }
    //     return dp[i][j] = 1 + min(solve(i - 1, j, s1, s2, dp),
    //                               min(solve(i, j - 1, s1, s2, dp),
    //                                   solve(i - 1, j - 1, s1, s2, dp)));
    // }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // if(word1 == word2) return 0;
        // if(word1 == "") return m;
        // if(word2 == "") return n;
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(n - 1, m - 1, word1, word2, dp);

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // for (int i = 0; i <= n; i++)
        //     dp[i][0] = i;
        // for (int j = 0; j <= m; j++)
        //     dp[0][j] = j;

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (word1[i-1] == word2[j-1]) {
        //             dp[i][j] = dp[i - 1][j - 1];
        //         } 
        //         else {
        //             dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        //         }
        //     }
        // }
        // return dp[n][m];

        vector<int> dp(m + 1, 0);
        vector<int> cur(m + 1, 0);
        for (int j = 0; j <= m; j++)
            dp[j] = j;

        for (int i = 1; i <= n; i++) {
            cur[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] == word2[j-1]) {
                    cur[j] = dp[j - 1];
                } 
                else {
                    cur[j] = 1 + min(dp[j], min(cur[j - 1], dp[j - 1]));
                }
            }
            dp = cur;
        }
        return dp[m];
    }
};