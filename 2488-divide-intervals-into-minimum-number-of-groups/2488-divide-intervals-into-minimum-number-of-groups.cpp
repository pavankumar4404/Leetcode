class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq; // min heap to store end points
        for(auto i: intervals){
            int s = i[0];
            int e = i[1];
            //current starting > smallest ending
            if(!pq.empty() && pq.top() < s){
                pq.pop();
                // pq.push(e);
            }
            pq.push(e);
        }
        return pq.size();
    }
};