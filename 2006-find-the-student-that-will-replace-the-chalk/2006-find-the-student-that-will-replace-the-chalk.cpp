class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        int n = chalk.size();
        int q = k/sum;
        k = k - sum*q;
        for(int i = 0; i<n; i++){
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }
        return 0;
    }
};