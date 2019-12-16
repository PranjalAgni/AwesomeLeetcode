class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<int> dp(prices.size());
        dp[0] = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i - 1]);
            int diff = prices[i] - minPrice;
            dp[i] = max(diff, dp[i - 1]);
        }

        return dp[prices.size() - 1];
    }
};
