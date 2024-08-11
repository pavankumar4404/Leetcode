class Solution {
public:
    int lowerBound(vector<vector<int>> &jobs, int l, int end){
        int n = jobs.size();
        int r = n-1;
        int ans = n+1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(jobs[mid][0] >= end){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
    int solve(vector<vector<int>> &jobs, int i, vector<int> &dp){
        if(i >= jobs.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int next = lowerBound(jobs, i+1, jobs[i][1]);
        int take = jobs[i][2] + solve(jobs, next, dp);
        int notTaken = solve(jobs, i+1, dp);

        return dp[i] = max(take, notTaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < profit.size(); ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        int n = profit.size();
        vector<int> dp(n + 1, -1);
        return solve(jobs, 0, dp);
    }
};