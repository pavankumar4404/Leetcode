class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0 ;
        int xorr = x^y;
        while(xorr){
            ans += (xorr&1);
            xorr >>= 1;
        }
        return ans; 
    }
};