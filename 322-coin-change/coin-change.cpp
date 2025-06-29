class Solution {
public:
    int f(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amount % coins[0] == 0) {
                return dp[i][amount] = amount / coins[0];
            }
            return dp[i][amount] = 1e9;
        }

        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }
        int np = f(i - 1, coins, amount, dp);
        int p = 1e9;
        if (coins[i] <= amount) {
            p = 1 + f(i, coins, amount - coins[i], dp);
        }

        return dp[i][amount] = min(p, np);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        f(n - 1, coins, amount, dp);
        if (dp[n - 1][amount] == 1e9) {
            return -1;
        }
        return dp[n - 1][amount];
    }
};