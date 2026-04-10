class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for(int i=1;i<=amount;i++){
            dp[0][i]=1e9;
        }
        for (int i = 1; i <= n; i++) {
            for (int x = 1; x <= amount; x++) {
                int op1 = dp[i - 1][x]; // not pick
                int op2 = 1e9;

                if (x - coins[i - 1] >= 0)
                    op2 = 1+dp[i][x - coins[i - 1]];

                dp[i][x] = min(op1 , op2);
            }
        }

        return (dp[n][amount] >= 1e9 ? -1 : dp[n][amount]);
    }
};