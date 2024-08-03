class Solution {
    // int solve(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
    //     if(i == n-1) return grid[i][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int down = solve(i+1, j, n, grid, dp);
    //     int diag = solve(i+1, j+1, n, grid, dp);
    //     return dp[i][j] = grid[i][j] + min(down, diag);
    // }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(0, 0, n, triangle, dp);
        vector<int> dp(n, 0);
        for(int j=0; j<n; j++){
            dp[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> cur(i+2, 0);
            for(int j=i; j>=0; j--){
                int down = dp[j];
                int diag = dp[j+1];
                cur[j] = triangle[i][j] + min(down, diag);
            }
            dp = cur;
        }
        return dp[0];
    }
};