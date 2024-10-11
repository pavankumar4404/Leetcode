class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        //1 sort the array of indices acc. to arr. time
        int n = times.size();
        vector<int> indices(n, 0);
        for(int i=1; i<n; i++) indices[i] = i;

        sort(indices.begin(), indices.end(), [&](int i, int j){
            return times[i][0] < times[j][0];
        });

        //2. push all available chairs

        priority_queue<int, vector<int>, greater<int>> chairs;
        for(int i=0;i<n; i++) chairs.push(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;     //{lt, chair}
        for(int i: indices){
            int at = times[i][0];
            int lt = times[i][1];
            // check if chairs got freed up
            while(!pq.empty() && pq.top().first <= at){
                chairs.push(pq.top().second);
                pq.pop();
            }
            int chair = chairs.top(); //select least available chair
            chairs.pop();
            if(i == targetFriend){
                return chair;
            }
            pq.push({lt, chair});
        }
        return 0;
    }

};