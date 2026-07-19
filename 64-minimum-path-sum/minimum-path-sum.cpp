class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int up=1e9;
                int left=1e9;

                if(i-1>=0) up=dp[i-1][j];
                if(j-1>=0) left=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(up,left);
            }
        }
        return dp[m-1][n-1];
    }
};