class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(auto i:arr) mp[i]++;
        int n = 0;
        for(auto i:arr){
            if(mp[i] == 1) {
                n++;
                if(n == k) return i;
            }
        }
        return "";
    }
};