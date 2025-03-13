class Solution {
    int LCS(string text1, string text2,int m,int n,vector<vector<int>> &dp){

        if(m==0||n==0){
            return dp[m][n]=0;
        }

        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return dp[m][n]= 1+LCS(text1,text2,m-1,n-1,dp);
        }

        else{
            return dp[m][n]=max(LCS(text1,text2,m-1,n,dp),LCS(text1,text2,m,n-1,dp));
        }
        return 0;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));
        // return LCS(text1,text2,m,n,dp);

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }

                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};