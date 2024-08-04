class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        int mod = 1e9 + 7;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum = sum % mod + nums[j] % mod;
                ans.push_back(sum);
            }
        }
        sort(ans.begin(), ans.end());
        int lr = 0;
        for(int i=left-1; i<=right-1; i++){
            lr = (lr + ans[i]) % mod;
        }
        return lr;
    }
};