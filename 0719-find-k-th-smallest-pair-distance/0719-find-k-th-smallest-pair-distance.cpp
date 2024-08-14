class Solution {
public:
    // int arr[1000002] = {0};
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> arr(maxi + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int diff = abs(nums[i] - nums[j]);
                arr[diff]++;
            }
        }
        for (int i = 0; i < 1e6 + 2; i++) {
            k -= arr[i];
            if (k <= 0)
                return i;
        }
        return -1;
    }
};