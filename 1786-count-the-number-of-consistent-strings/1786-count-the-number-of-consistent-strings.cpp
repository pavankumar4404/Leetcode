class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for(char c: allowed){
            int a = c-'a';
            mask = (mask | (1 << a));
        }
        int ans = 0;
        for(int i=0; i<words.size(); i++){
            bool f = 1;
            for(char c: words[i]){
                if( (1 << (c - 'a')) & mask);
                else{
                    f = 0;
                }
            }
            if(f) ans++;
        }
        return ans;
    }
};