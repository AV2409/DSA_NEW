class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<long long>> dp(n2 + 1, vector<long long>(n1 + 1));
        const long long MOD=1e18+7;
        for(int i=0;i<=n1;i++){
            dp[0][i]=1;
        }
        for (int i = 1; i <= n2; i++) {
            for (int j = 1; j <= n1; j++) {
                if(s[j-1]==t[i-1]) dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%MOD;
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[n2][n1];
    }
};