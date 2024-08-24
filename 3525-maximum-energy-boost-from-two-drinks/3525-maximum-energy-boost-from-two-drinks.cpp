class Solution {
public:
    long long solve(int i, int last, vector<int> &A, vector<int> &B, vector<vector<long long>> &dp){
        if(i == 0){
            if(last == 0) return A[i];
            else return B[i];
        }
        if(dp[i][last] != -1) return dp[i][last];

        long long stay = INT_MIN;
        if(last == 0) stay = A[i] + solve(i-1, 0, A, B, dp);
        else stay = B[i] + solve(i-1, 1, A, B, dp);
        long long leave = INT_MIN;
        if(last == 0) leave = solve(i-1, 1, A, B, dp);
        else leave = solve(i-1, 0, A, B, dp);

        return dp[i][last] = max(leave, stay);
    }
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(n+1, vector<long long> (2, -1));
        long long a = solve(n-1, 0, energyDrinkA, energyDrinkB, dp);
        long long b = solve(n-1, 1, energyDrinkA, energyDrinkB, dp);
        return max(a, b);
    }
};