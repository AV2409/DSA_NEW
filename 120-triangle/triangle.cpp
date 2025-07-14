class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, int n,
          vector<vector<int>>& dp) {
        if (i == n - 1)
            return dp[i][j] = triangle[i][j];

        if (i > n - 1)
            return 1e9;

        if (dp[i][j] != -1)
            return dp[i][j];
        int down = f(i + 1, j, triangle, n, dp);
        int diag = f(i + 1, j + 1, triangle, n, dp);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, triangle, n, dp);
    }
};