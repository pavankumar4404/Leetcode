// #define ll long long
// class Solution {
// public:
//     int n, m;
//     ll solve(int i, int j, vector<vector<int>> &points, vector<vector<ll>> &dp){
//         if(i<0 || j<0 || j>=m){
//             return 0;
//         }
//         if(i == 0){
//             return points[i][j];
//         }

//         if(dp[i][j] != -1) return dp[i][j];
//         ll pick = points[i][j];
//         ll best = 0;
//         for(int col=0; col<m; col++){
//             ll temp = -1*abs(j-col) + solve(i-1, col, points, dp);
//             best = max(temp, best);
//         }
//         return dp[i][j] = pick + best;
//     }
//     ll maxPoints(vector<vector<int>>& points) {
//         n = points.size();
//         m = points[0].size();
//         ll ans = 0;
//         vector<vector<ll>> dp(n+1, vector<ll>(m, -1));
//         for(int col=0; col<m; col++){
//             ll temp = solve(n-1, col, points, dp);
//             ans = max(temp, ans);
//         }
//         return ans;
//     }
// };
// O(m*n^2)

#define ll long long
class Solution {
public:
    ll maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        vector<ll> dp(m, 0);

        // Initialize the dp with the first row values
        for (int j = 0; j < m; ++j) {
            dp[j] = points[0][j];
        }

        // Process each row
        for (int i = 1; i < n; ++i) {
            vector<ll> left(m, 0), right(m, 0), cur_row(m, 0);

            // Compute left-to-right max values
            left[0] = dp[0];
            for (int j = 1; j < m; ++j) {
                left[j] = max(left[j - 1] - 1, dp[j]);
            }

            // Compute right-to-left max values
            right[m - 1] = dp[m - 1];
            for (int j = m - 2; j >= 0; --j) {
                right[j] = max(right[j + 1] - 1, dp[j]);
            }

            // Calculate the new dp values using the precomputed left and right arrays
            for (int j = 0; j < m; ++j) {
                cur_row[j] = points[i][j] + max(left[j], right[j]);
            }

            dp = cur_row; // Update dp for the next row
        }
        long long ans = 0;
        for (int i = 0; i < m; ++i)
            ans = max(ans, dp[i]);
        return ans;
    }
};
