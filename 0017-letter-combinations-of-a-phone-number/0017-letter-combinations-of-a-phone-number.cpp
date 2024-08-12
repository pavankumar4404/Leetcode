class Solution {
public:
    // unordered_map<char, string> mp;
    vector<string> mp;
    vector<string> ans;
    void solve(int i, string &digits, string &temp){
        if(i == digits.size()) {
            ans.push_back(temp);
            return;
        }
        string s = mp[digits[i] - '0'];

        for(int j=0; j<s.size(); j++){
            temp.push_back(s[j]);
            solve(i+1, digits, temp);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        mp.resize(12);
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string temp = "";
        solve(0, digits, temp);
        return ans;
    }
};