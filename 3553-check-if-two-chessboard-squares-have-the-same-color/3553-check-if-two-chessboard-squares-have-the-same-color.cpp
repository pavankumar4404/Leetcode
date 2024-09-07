class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int i = (coordinate1[0]-'a')+(coordinate1[1]-'0');
        int j = (coordinate2[0]-'a')+(coordinate2[1]-'0');
        return i%2 == j%2;
    }
};