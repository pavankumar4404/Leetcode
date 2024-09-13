class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int qr = queries.size();
        vector<int> ans(qr);
        vector<int> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i]^arr[i];
        }
        for(int i = 0; i<qr; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = prefix[r+1] ^ prefix[l];
        }
        return ans;
    }
};