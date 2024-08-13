class Solution {
public:
    void f(int ind, int n, int target, vector<vector<int>>& arr,
           vector<int>& nums, vector<int>& temp) {
        if (target == 0) {
            arr.push_back(temp);
            return;
        }

        for (int i = ind; i < n; i++) {
            if (nums[i] > target)
                break;
            if (i > ind && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            f(i + 1, n, target - nums[i], arr, nums, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> arr;
        int n = nums.size();
        vector<int> temp;
        sort(nums.begin(), nums.end());
        f(0, n, target, arr, nums, temp);
        return arr;
    }
};