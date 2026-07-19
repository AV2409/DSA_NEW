class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        
        dp[0][0]=triangle[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                if(i==0 && j==0) continue;
                int up=1e9;
                int diag=1e9;

                if(i-1>=0) up=dp[i-1][j];
                if(j-1>=0) diag=dp[i-1][j-1];
                dp[i][j]=triangle[i][j]+min(up,diag);
            }
        }
        int mini=1e9;
        for(int i=0;i<n;i++){
            mini=min(mini,dp[m-1][i]);
        }
        return mini;
    }
};