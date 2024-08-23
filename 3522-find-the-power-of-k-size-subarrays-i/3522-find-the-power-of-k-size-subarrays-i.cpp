class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i<n-k+1; i++){
            bool valid = 1;
            for(int j=i; j<i+k; j++){
                if(nums[j] - nums[i] != j-i){
                    ans.push_back(-1);
                    valid = 0;
                    break;
                }
            }
            if(valid){
                ans.push_back(nums[i + k - 1]);
            }
        }
        return ans;
    }
};