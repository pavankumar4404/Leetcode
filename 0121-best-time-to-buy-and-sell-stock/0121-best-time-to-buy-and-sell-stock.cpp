class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        if (n == 0) {
            return profit;
        }
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};