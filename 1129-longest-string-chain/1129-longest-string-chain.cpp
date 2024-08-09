class Solution {
    bool check(string &a, string &b){
        int n1 = a.length();
        int n2 = b.length();
        if(abs(n1 - n2) != 1) return false;
        if(n1 < n2){
            swap(a, b);
            swap(n1,n2);
        }
        int i=0;
        int j=0;
        while(i<n1){
            if(a[i] == b[j]){
                i++, j++;
            }
            else{
                i++;
            }
        }
        if(i==n1 && j==n2) return true;
        return false;
    }
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), comp);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(check(words[i], words[j]) && 1 + dp[j] > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        // for(int i=0; i<n; i++){

        // }
    }
};