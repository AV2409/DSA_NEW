class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int op1=0;
                int op2=0;
                if(i-1>=0) op1=dp[i-1][j];
                if(j-1>=0) op2=dp[i][j-1];
                dp[i][j]=op1+op2;
            }
        }
        return dp[m-1][n-1];
    }
};