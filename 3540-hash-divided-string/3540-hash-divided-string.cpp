class Solution {
public:
    string stringHash(string s, int k) {
        int n = s.size();
        string ans;
        for(int i=0; i<n; i+=k){
            int idx = 0;
            for(int j=i; j<i+k; j++){
                idx += (s[j] - 'a');
            }
            idx %= 26;
            ans.push_back('a' + idx);
        }
        return ans;
    }
};