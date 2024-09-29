class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:

    long long countOfSubstrings(string s, int k) {
        int n = s.size();

        vector<int> pref(n, 0);
        if( !isVowel( s[0] ) ) 
            pref[0] = 1;
        for(int i=1; i<n; i++){
            if(!isVowel(s[i])) pref[i] = pref[i-1] + 1;
            else pref[i] = pref[i-1];
        }
        
        long long ans = 0;
        int i=0, j=0;
        unordered_map<char, int> mp;
        int cons = 0;
        while(j<n){
            char c = s[j];
            if(isVowel(c)){
                mp[c]++;
            }
            else{
                cons++;
            }
            while(cons > k){
                if(isVowel(s[i])){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                }
                else{
                    cons--;
                }
                i++;
            }
            
            while(mp.size() >= 5 && k == cons){
                // ans++;
                int k = upper_bound(pref.begin(), pref.end(), pref[j]) - pref.begin();
                ans += (long long)(k-j);
                if(isVowel(s[i])){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                }
                else{
                    cons--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};