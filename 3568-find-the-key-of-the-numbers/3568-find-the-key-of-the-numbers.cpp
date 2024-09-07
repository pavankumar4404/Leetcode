class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int b = 1;
        int ans = 0;
        while(max({num1, num2, num3}) > 0){
            ans += min({num1 % 10, num2 % 10, num3 % 10})*b;
            b*=10;
            num1/=10;
            num3/=10;
            num2/=10;
        }
        return ans;
    }
};