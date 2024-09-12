class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> s(allowed.begin(), allowed.end());
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            bool f = 1;
            for(char c:words[i]){
                if(s.find(c) == s.end()){
                    f=0;
                    break;
                }
            }
            if(f) ans++;
        }
        return ans;
    }
};