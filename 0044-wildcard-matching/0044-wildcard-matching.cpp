class Solution {
    int solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i<0 && j<0) return 1;
        if(j<0 && i>=0) return 0;
        if(i<0 && j>=0){ //check for only '*'
            while(j>=0){
                if(p[j] != '*') return 0;
                j--;
            }
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }
        if(p[j] == '*'){
            return dp[i][j] = solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp);
        }
        return dp[i][j] = 0;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s, p, dp);
    }
};