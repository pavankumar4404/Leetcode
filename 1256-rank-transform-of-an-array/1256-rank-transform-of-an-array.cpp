class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;
        for(int i: arr){
            mp[i]=1;
        }
        int rank = 1;
        for(auto &it: mp){
            it.second = rank;
            rank++;
        }
        vector<int> ans(arr.size());
        for(int i=0; i<arr.size(); i++){
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};