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

        // vector<int> dp(n+1, 0), cur(n+1, 0);
        // for(int i=n-1; i>=0; i--){
        //     for(int previ = i-1; previ >= -1; previ--){
        //         int maxi = dp[previ + 1];
        //         if(previ == -1 || arr[i] > arr[previ]){
        //             maxi = max(maxi, 1 + dp[i+1]);
        //         }
        //         cur[previ + 1] = maxi;
        //     }
        //     dp = cur;
        // }
        // return dp[0];

        // vector<int> dp(n, 1);
        // int lis = 1;
        // for(int i=0; i<n; i++){
        //     for(int prev=0; prev<i; prev++){
        //         if(arr[prev] < arr[i]){
        //             dp[i] = max(dp[i], 1 + dp[prev]);
        //         }
        //     }
        //     lis = max(lis, dp[i]);
        // }
        // return lis;

        // bs
        vector<int> temp;
        temp.push_back(arr[0]);
        for(int i=1; i<n; i++){
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[idx] = arr[i];
            }
        }
        return temp.size();
    }
};