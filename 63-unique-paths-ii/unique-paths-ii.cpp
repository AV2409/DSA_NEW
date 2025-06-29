class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int x1 = 0;
                    int x2 = 0;
                    if (i > 0) {
                        x1 = dp[i - 1][j];
                    }
                    if (j > 0) {
                        x2 = dp[i][j - 1];
                    }
                    dp[i][j] = x1 + x2;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};