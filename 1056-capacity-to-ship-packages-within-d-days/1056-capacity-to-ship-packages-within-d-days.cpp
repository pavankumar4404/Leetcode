class Solution {
public:
    bool checkDays(vector<int>& arr, int mid, int days) {
        int requiredDays = 1;
        int load = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] + load > mid) {
                requiredDays++;
                load = arr[i];
            } 
            else {
                load += arr[i];
            }
        }
        return requiredDays <= days;
    }

    int shipWithinDays(vector<int>& nums, int days) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            if (checkDays(nums, mid, days)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};