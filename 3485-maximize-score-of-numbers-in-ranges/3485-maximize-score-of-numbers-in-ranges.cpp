class Solution {
public:
    bool check(vector<int> &start, int d, long long mid) {
        int prev = start[0];
        for(int i=1; i<start.size(); i++){
            if(start[i] - prev >= mid){
                prev = start[i];
                continue;
            }
            else{
                if((start[i] - prev + d) < mid){
                    return false;
                }
                prev = prev + mid;
            }
            // prev = start[i];
        }
        return true;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());

        long long left = 0;
        long long right = INT_MAX;
        long long ans = 0;

        while (left <= right) {
            long long mid = (left + right)/2;
            if (check(start, d, mid)) {
                ans = mid;
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};