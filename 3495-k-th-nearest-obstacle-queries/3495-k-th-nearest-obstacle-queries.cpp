class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> pq;
        int n = queries.size();
        vector<int> ans(n, -1);
        if(k > n) return ans;
        for(int i=0; i<n; i++){
            int d = abs(queries[i][0]) + abs(queries[i][1]);
            pq.push(d);
            if(pq.size() > k){
                pq.pop();
            }
            if(pq.size() == k) ans[i] = pq.top();   
        }
        return ans;
    }
};