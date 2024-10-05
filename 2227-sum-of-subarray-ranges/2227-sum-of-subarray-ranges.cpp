class Solution {
public:
    vector<int> NSE(vector<int> &arr, int n){
        stack<int> s;
        vector<int> nse(n, n);      //high to low
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(!s.empty()) nse[i] = s.top();
            s.push(i);
        }
        return nse;
    }
    vector<int> PSE(vector<int> &arr, int n){
        stack<int> s;
        vector<int> pse(n, -1);  // prev smaller or equal idx (high to low)
        for(int i=0; i<n; i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                s.pop();
            }
            if(!s.empty()) pse[i] = s.top();
            s.push(i);
        }
        return pse;
    }
    vector<int> NGE(vector<int> &arr, int n){
        stack<int> s;    //low to high
        vector<int> nge(n, n);
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()] <= arr[i]){
                s.pop();
            }
            if(!s.empty()) nge[i] = s.top();
            s.push(i);
        }
        return nge;
    }
    vector<int> PGE(vector<int> &arr, int n){
        stack<int> s;
        vector<int> pge(n, -1);  // prev greater or equal idx (low to high)
        for(int i=0; i<n; i++){
            while(!s.empty() && arr[s.top()] < arr[i]){
                s.pop();
            }
            if(!s.empty()) pge[i] = s.top();
            s.push(i);
        }
        return pge;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int> nse = NSE(nums, n);
        vector<int> pse = PSE(nums, n);
        vector<int> nge = NGE(nums, n);
        vector<int> pge = PGE(nums, n);
        for(int i=0; i<n; i++){
            long long asMax = (nge[i] - i) * (i - pge[i]);
            long long asMin = (nse[i] - i) * (i - pse[i]);
            ans += (asMax * nums[i] - asMin * nums[i]);
        }
        return ans;
    }
};