class Solution {
public:
    int lowerBound(vector<vector<int>> &events, int l, int end){
        int n = events.size();
        int r = n-1;
        int ans = n+1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(events[mid][0] >= end){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int solve(int i, int k, vector<vector<int>> &events, vector<vector<int>> &dp){
        if(i >= events.size() || k <= 0) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int next = lowerBound(events, i+1, events[i][1] + 1);
        int taken = events[i][2] + solve(next, k-1, events, dp);
        int notTaken = solve(i+1, k, events, dp);

        return dp[i][k] = max(taken, notTaken);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return solve(0, k, events, dp);
    }
};