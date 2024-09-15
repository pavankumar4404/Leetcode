class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        int mask = 0;
        unordered_map<int, int> prefix;
        prefix[0] = -1;
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            if(vowel.find(s[i]) != vowel.end()){
                int num = s[i] - 'a' + 1;
                mask ^= (1 << num);
                if(prefix.find(mask) != prefix.end()){
                    ans = max(ans, i - prefix[mask]);
                }
                else prefix[mask] = i;
            }
            else {
                ans = max(ans, i - prefix[mask]);
            }
        }
        return ans;
    }
};