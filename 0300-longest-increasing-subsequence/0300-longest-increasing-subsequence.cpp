class Solution {
    // int lis(int i, int previ, vector<int> &arr, vector<vector<int>> &dp){
    //     if(i == arr.size()) return 0;

    //     if(dp[i][previ + 1] != -1) return dp[i][previ + 1];
    //     int maxi = lis(i+1, previ, arr, dp);
    //     if(previ == -1 || arr[i] > arr[previ]){
    //         maxi = max(maxi, 1 + lis(i+1, i, arr, dp));
    //     }
    //     return dp[i][previ + 1] = maxi;
    // }
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return lis(0, -1, arr, dp);

        vector<int> dp(n+1, 0), cur(n+1, 0);
        for(int i=n-1; i>=0; i--){
            for(int previ = i-1; previ >= -1; previ--){
                int maxi = dp[previ + 1];
                if(previ == -1 || arr[i] > arr[previ]){
                    maxi = max(maxi, 1 + dp[i+1]);
                }
                cur[previ + 1] = maxi;
            }
            dp = cur;
        }
        return dp[0];
    }
};