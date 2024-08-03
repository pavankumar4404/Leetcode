class Solution {
public:
// int mod=int(1e9+7);
    // int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
    //     if(i>=0 && j>=0 && mat[i][j]==1) return 0;
    //     if(i==0 && j==0) return 1;
    //     if(i<0 || j<0) return 0;

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int up=solve(i-1,j,mat,dp);
    //     int left=solve(i,j-1,mat,dp);
    //     return dp[i][j]=(up+left);
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1] == 1) return 0;
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,obstacleGrid,dp);
        vector<int> prev(m, 0);
        prev[0] = 1;
        for(int i=0; i<n; i++){
            vector<int> cur(m, 0);
            for(int j=0; j<m; j++){
                if(i==0 && j==0) {
                    cur[j] = 1;
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    cur[j] = 0;
                    continue;
                }
                int up = 0, left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = cur[j-1];
                cur[j] = up+left;
            }
            prev = cur;
        }
        return prev[m-1];
    }
};