class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e9));
        dp[1][1] = triangle[0][0];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= i; j++) {
                if (i == 1 && j == 1)
                    continue;
                dp[i][j] = min(dp[i - 1][j] + triangle[i - 1][j - 1],
                               dp[i-1][j - 1]+triangle[i - 1][j - 1]);
            }
        }
        int ans=1e9;
        for(int i=1;i<=n;i++){
            ans=min(ans,dp[m][i]);
        }
        return ans;
    }
};