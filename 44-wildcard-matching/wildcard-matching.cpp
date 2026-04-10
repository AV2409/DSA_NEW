class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1));
        dp[0][0] = true;

        for(int i=1;i<=n2;i++){
            if(p[i-1]=='*') dp[0][i]=dp[0][i-1];
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if(p[j-1]=='*'||p[j-1]=='?'){
                    if(p[j-1]=='?'){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        bool op1=dp[i-1][j];
                        bool op2=dp[i][j-1];
                        dp[i][j]=op1||op2;
                    }
                }
                else{
                    if(p[j-1]==s[i-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        return dp[n1][n2];
    }
};