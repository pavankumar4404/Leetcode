class Solution {
public:
     vector<vector<int>>  spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> dir =  {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // east, south, west, north
         vector<vector<int>> res;  
        int len = 0, d = 0; // move <len> steps in the <d> direction
        res.push_back({r0, c0});
        while (res.size() < R * C) {
            if (d == 0 || d == 2) len++; // when move east or west, the length of path need plus 1 
            for (int i = 0; i < len; i++) {
                r0 += dir[d][0];
                c0 += dir[d][1];
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) // check valid
                    res.push_back({r0, c0});
            }
            d = (d + 1) % 4; // turn to next direction
        }
        return res;
    }
};