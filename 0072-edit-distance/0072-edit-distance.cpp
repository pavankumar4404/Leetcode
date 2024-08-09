class Solution {
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(j < 0) return i+1;
        if(i < 0) return j+1;

        if(dp[i][j] != -1) return dp[i][j];

        int del = 0, rep = 0, ins = 0;
        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i-1, j-1, s1, s2, dp);
        }
        else{
            del = 1 + solve(i-1, j, s1, s2, dp);
            ins = 1 + solve(i, j-1, s1, s2, dp);
            rep = 1 + solve(i-1, j-1, s1, s2, dp);
        }
        return dp[i][j] = min(del, min(ins, rep));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(word1 == word2) return 0;
        if(word1 == "") return m;
        if(word2 == "") return n;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};