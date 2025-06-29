class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int x = triangle[n - 1].size();

        for (int i = 0; i < x; i++) {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            int len = triangle[i].size();
            for (int j = 0; j < len; j++) {
                int d = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];

                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }
};