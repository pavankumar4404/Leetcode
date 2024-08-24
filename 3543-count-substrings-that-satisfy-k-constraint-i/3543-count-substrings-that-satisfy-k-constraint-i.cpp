class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            int z = 0;
            int o = 0;
            for(int j = i; j<n; j++){
                if(s[j] == '0') z++;
                else o++;
                if(o > k && z > k){
                    break;
                }
                ans++;
            }
        }
        return ans;
    }
};