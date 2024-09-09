class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long cur = nums[0];
        long long previ = 0;
        long long ans = 0;
        for(int i=1; i<n-1; i++){
            if(nums[i] > cur){
                ans += cur * (i - previ);
                previ = i;
                cur = nums[i];
            }
        }
        ans += cur * (n - 1 - previ);
        return ans;
    }
};