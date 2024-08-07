class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // string rev = s;
        // reverse(rev.begin(), rev.end());
        vector<int> dp(m+1, 0), cur(m+1, 0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    cur[j] = 1 + dp[j-1];
                }
                else{
                    cur[j] = max(dp[j], cur[j-1]);
                }
            }
            dp = cur;
        }
        return n + m - 2*dp[m];
    }
};