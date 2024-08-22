class Solution {
public:
    int findComplement(int num) {
        int dig = log2(num) + 1;
        int mask = pow(2, dig) - 1;
        return (num^mask);
    }
};