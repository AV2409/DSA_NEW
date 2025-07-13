class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                int x1 = 0, x2 = 0;
                if (i > 0)
                    x1 = dp[i - 1][j];
                if (j > 0)
                    x2 = dp[i][j - 1];
                dp[i][j] = x1 + x2;
            }
        }
        return dp[m - 1][n - 1];
    }
};