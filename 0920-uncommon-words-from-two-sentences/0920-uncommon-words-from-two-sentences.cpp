class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> s;
        string temp = "";
        for(int i=0;i<s1.length(); i++){
            if(s1[i] == ' '){
                s[temp]++;
                temp = "";
            }
            else temp.push_back(s1[i]);
        }
        s[temp]++;
        temp = "";
        for(int i=0;i<s2.length(); i++){
            if(s2[i] == ' '){
                s[temp]++;
                temp = "";
            }
            else temp.push_back(s2[i]);
        }
        s[temp]++;
        vector<string> ans;
        for(auto i: s){
            if(i.second <= 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};