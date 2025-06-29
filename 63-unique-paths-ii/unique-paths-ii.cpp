class Solution {
public:
    int f(int m, int n, vector<vector<int>>& obstacleGrid,
          vector<vector<int>>& dp) {
        if (m < 0 || n < 0) {
            return 0;
        }
        if (obstacleGrid[m][n] == 1) {
            return dp[m][n] = 0;
        }
        if (m == 0 && n == 0) {
            return dp[m][n] = 1;
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        int u = f(m - 1, n, obstacleGrid, dp);
        int r = f(m, n - 1, obstacleGrid, dp);
        return dp[m][n] = u + r;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, obstacleGrid, dp);
    }
};