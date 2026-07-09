class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();

        if (s3.size() != n + m) return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) continue;
                int k = i + j - 1;
                bool op1=false;
                bool op2=false;
                if (i > 0 && s1[i - 1] == s3[k])
                    op1= dp[i - 1][j];
                if (j > 0 && s2[j - 1] == s3[k])
                    op2= dp[i][j - 1];
                
                dp[i][j]=op1|op2;
            }
        }

        return dp[n][m];
    }
};