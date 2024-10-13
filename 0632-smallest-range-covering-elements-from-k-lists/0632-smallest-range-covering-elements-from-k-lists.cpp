class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int range = INT_MAX;
        int start = 1e6;
        int end = 1e6;
        int maxi = INT_MIN;

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>> pq;
        //{value, {listIdx, valIdx}}
        for(int i=0; i<n; i++){
            pq.push({nums[i][0], {i, 0}});
            maxi = max(maxi, nums[i][0]);
        }
        while(pq.size() == nums.size()){
            auto [mini, ind] = pq.top();
            pq.pop();
            int row = ind.first;
            int col = ind.second;

            if(maxi - mini < range){
                range = maxi - mini;
                start = mini;
                end = maxi;
            }

            if(col + 1 < nums[row].size()){
                int next = nums[row][col + 1];
                pq.push({next, {row, col + 1}});
                maxi = max(next, maxi);
            }
        }
        return {start, end};
    }
};