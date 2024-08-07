class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // string rev = s;
        // reverse(rev.begin(), rev.end());
        vector<int> dp(n+1, 0), cur(n+1, 0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == s[n-j]){
                    cur[j] = 1 + dp[j-1];
                }
                else{
                    cur[j] = max(dp[j], cur[j-1]);
                }
            }
            dp = cur;
        }
        return dp[n];
    }
};