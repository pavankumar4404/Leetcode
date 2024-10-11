class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int cnt0 = 0;
        while(j<n){
            if(nums[j] == 0) cnt0++;
            //no need to fully shrink the window just find best
            if(cnt0 > k){
                if(nums[i] == 0) cnt0--;
                i++;
            }
            // ans = max(ans, j-i+1);
            j++;
        }
        //last window will be the maximum
        return n-i;
    }
};