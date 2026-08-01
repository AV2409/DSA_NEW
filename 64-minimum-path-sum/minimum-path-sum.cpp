class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        dp[0][0]=grid[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                int op1=1e8;
                int op2=1e8;

                if(i-1>=0) op1=dp[i-1][j];
                if(j-1>=0) op2=dp[i][j-1];

                dp[i][j]=min(op1,op2)+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};