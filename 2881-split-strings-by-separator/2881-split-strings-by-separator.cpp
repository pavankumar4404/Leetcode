class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        int n = words.size();
        for(int i=0; i<n; i++){
            string s;
            for(char c: words[i]){
                if(c == separator){
                    if(s.size() > 0) ans.push_back(s);
                    s = "";
                }
                else{
                    s.push_back(c);
                }
            }
            if(s.size() > 0) ans.push_back(s);
        }
        return ans;
    }
};