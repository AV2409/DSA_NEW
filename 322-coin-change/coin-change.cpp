class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 1e9));

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                int np = dp[i - 1][j];
                int p = 1e9;
                if (coins[i - 1] <= j) {
                    p = 1 + dp[i][j - coins[i - 1]];
                }
                dp[i][j] = min(p, np);
            }
        }

        // for (auto i : dp)
        // {
        //     for (auto j : i)
        //     {
        //         if (j == 1e9)
        //             cout << "i" << "\t";
        //         else
        //             cout << j << "\t";
        //     }
        //     cout << endl;
        // }

        if (dp[n][amount] == 1e9) {
            return -1;
        }
        return dp[n][amount];
    }
};