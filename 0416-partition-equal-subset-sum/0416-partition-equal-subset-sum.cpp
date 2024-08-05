class Solution {
    // bool solve(int i, int target, vector<int> &arr, vector<vector<int>> &dp){
    //     if(target == 0) return true;
    //     if(i==0) return arr[0] == target;

    //     if(dp[i][target] != -1) return dp[i][target];
        
    //     bool notpick = solve(i-1, target, arr, dp);
    //     bool pick = false;
    //     if(target >= arr[i]){
    //         pick = solve(i-1, target - arr[i], arr, dp);
    //     }
    //     return dp[i][target] = (pick || notpick);
    // }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 == 1) return false;
        // vector<vector<bool>> dp(n, vector<bool>(sum/2 + 1, false));
        // // return solve(n-1, sum/2, nums, dp);

        // for(int i=0; i<n; i++){
        //     dp[i][0] = true;
        // }
        // if(nums[0] <= sum/2) dp[0][nums[0]] = true;
        // int k = sum/2;
        // for(int i=1; i<n; i++){
        //     for(int target = 1; target <= k; target++){
        //         bool notpick = dp[i-1][target];
        //         bool pick = false;
        //         if(target >= nums[i]){
        //             pick = dp[i-1][target-nums[i]];
        //         }
        //         dp[i][target] = (pick || notpick);
        //     }
        // }
        // return dp[n-1][k];

        int k = sum/2;
        vector<bool> dp(k+1, false);
        for(int i=0; i<n; i++){
            dp[0] = true;
        }
        if(nums[0] <= sum/2) dp[nums[0]] = true;
        for(int i=1; i<n; i++){
            vector<bool> cur(k+1, false);
            for(int target = 1; target <= k; target++){
                bool notpick = dp[target];
                bool pick = false;
                if(target >= nums[i]){
                    pick = dp[target-nums[i]];
                }
                cur[target] = (pick || notpick);
            }
            dp = cur;
        }
        return dp[k];
    }
};