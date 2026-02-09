class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1e9;
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 0; i < n; i++) {
            dp[m - 1][i] = matrix[m - 1][i];
        }

        for (int i = m - 2; i >= 0;i--) {
            for (int j = 0; j < n; j++) {
                int op1;
                int op2 = 1e9;
                int op3 = 1e9;

                op1 = matrix[i][j] + dp[i + 1][j];
                if (j > 0)
                    op2 = matrix[i][j] + dp[i + 1][j - 1];
                if (j < n - 1)
                    op3 = matrix[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min({op1, op2, op3});
            }
        }

        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};