class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int n  = nums.size();
        int len = 0;
        int maxlen = 0;
        for(int i=0; i<n; i++ ){
            if(nums[i] == maxi){
                len++;
                maxlen = max(len, maxlen);
            }
            else{
                len = 0;
            }
        }
        return maxlen;
    }
};