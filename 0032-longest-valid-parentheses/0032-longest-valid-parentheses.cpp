class Solution {
public:
    // vector<vector<int>> dp;
    // int solve(int i, int open, string &s){
    //     if(open < 0) return INT_MIN;
    //     if(i == s.size()){
    //         if(open == 0) return 0;
    //         return INT_MIN;
    //     }
    //     if(dp[i][open] != -1) return dp[i][open];

    //     int pick = 0;
    //     if(s[i] == '(') pick = 1 + solve(i+1, open + 1, s);
    //     else pick = 1 + solve(i+1, open - 1, s);
    //     int dontpick = solve(i+1, open, s);
    //     return max(pick, dontpick);
    // }
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int t = st.top();
            if (t != -1 && s[i] == ')' && s[t] == '(') {
                st.pop();
                ans = max(ans, i - st.top());
            } else
                st.push(i);
        }
        return ans;
    }
};