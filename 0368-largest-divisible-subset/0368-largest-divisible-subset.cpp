
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> hash(n, 1);
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0  && 1 + dp[j] > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
        }
        int lds = -1;
        int last = -1;
        for(int i=0; i<n; i++){
            if(dp[i] > lds){
                lds = dp[i];
                last = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last]);
        while(last != hash[last]){
            last = hash[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



