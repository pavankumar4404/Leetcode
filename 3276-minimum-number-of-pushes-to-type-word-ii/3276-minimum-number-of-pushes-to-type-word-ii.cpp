class Solution {
public:
    int minimumPushes(string word) {
        // unordered_map<int,int> mp;
        vector<int> freq(26, 0);
        int n = word.length();
        for (int i = 0; i < n; i++) {
            freq[(word[i] - 'a')]++;
        }
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if(freq[i] == 0) break;
            ans += (freq[i] * (i/8 + 1));
        }
        return ans;
    }
};