class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = n - 1; i >= 0; i--) {
        // buy case
        int price_buy = -prices[i] + dp[i + 1][0];
        int price_not_buy = dp[i + 1][1];
        dp[i][1] = max(price_buy, price_not_buy);

        // sell case
        int price_sell = prices[i] + dp[i + 1][1];
        int price_not_sell = dp[i + 1][0];

        dp[i][0] = max(price_sell, price_not_sell);
    }
    return dp[0][1];
}
};