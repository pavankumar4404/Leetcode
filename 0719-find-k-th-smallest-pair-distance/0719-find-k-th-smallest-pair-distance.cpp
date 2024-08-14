class Solution {
public:
    int check(vector<int>& nums, int mid) {
        int pairs = 0;
        int i = 0;
        int j = 1, n = nums.size();
        while(j < n){
            while (j < n && nums[j] - nums[i] > mid)
                i++;
        
            pairs += (j - i);
            j++;
        }
        return pairs;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n - 1] - nums[0];
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int countPairs = check(nums, mid);
            if (countPairs < k) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};