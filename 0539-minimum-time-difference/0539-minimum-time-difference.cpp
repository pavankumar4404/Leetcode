class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n =  timePoints.size();
        vector<int> minutes;
        for(string s: timePoints){
            int h = stoi(s.substr(0, 2));
            int m = stoi(s.substr(3, 2));
            int mint = h*60 + m;
            minutes.push_back(mint);
        }
        sort(minutes.begin(), minutes.end());
        int ans = INT_MAX;
        for(int i=1; i<n; i++){
            ans = min(ans, minutes[i] - minutes[i-1]);
        }
        ans = min(ans, (1440 - minutes[n-1]) + minutes[0]);
        return ans;
    }
};