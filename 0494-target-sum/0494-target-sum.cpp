class Solution {
    int solve(int i, int sum, vector<int> &nums, vector<vector<int>> &dp, int offset) {
        if (i == -1) {
            return sum == 0 ? 1 : 0;
        }
        if (sum + offset < 0 || sum + offset >= dp[0].size()) {
            return 0;
        }
        if (dp[i][sum + offset] != INT_MIN) return dp[i][sum + offset];
        int pos = solve(i - 1, sum + nums[i], nums, dp, offset);
        int neg = solve(i - 1, sum - nums[i], nums, dp, offset);
        return dp[i][sum + offset] = pos + neg;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total) return 0; // Early exit if target is not reachable
        
        // Initialize dp array with INT_MIN
        vector<vector<int>> dp(n, vector<int>(2 * total + 1, INT_MIN));
        
        // Offset to handle negative indices
        int offset = total;

        return solve(n - 1, target, nums, dp, offset);
    }
};
