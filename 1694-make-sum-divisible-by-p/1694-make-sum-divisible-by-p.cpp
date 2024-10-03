class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> prefix;
        int total = 0;
        for(int num: nums){
            total = (total + num) % p;
        }
        int target = total;
        if(target == 0) return 0;

        prefix[0] = -1;
        int len = n;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum = (sum + nums[i]) % p;
            int need = (sum - target + p) % p;

            if(prefix.find(need) != prefix.end()){
                len = min(len, i - prefix[need]);
            }
            prefix[sum] = i;
        }
        return (len == n) ? -1 : len;
    }
};