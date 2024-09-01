class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s = original.size();
        vector<vector<int>> arr;
        if(s != n*m) return arr;
        arr.resize(m, vector<int>(n));
        for(int j=0; j<s; j++){
            arr[j / n][j % n] = original[j];
        }
        return arr;
    }
};