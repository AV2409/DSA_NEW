class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int m = triangle[0].size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (i == n - 1)
                dp[i][j] = triangle[i][j];
            else {
                int down = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];

                dp[i][j] = triangle[i][j] + min(down, diag);
            }
        }
    }
    return dp[0][0];
    }
};