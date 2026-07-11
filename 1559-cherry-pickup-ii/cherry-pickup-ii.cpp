class Solution {
public:

    int rows;
    int cols;
    vector<vector<vector<int>>>dp;
    int f(int row,int j,int y,vector<vector<int>>& grid){
        if(row==rows) return 0;
        if(dp[row][j][y]!=-1) return dp[row][j][y];
        int ans=0;
        for(int dj=-1;dj<=1;dj++){
            int nj=j+dj;
            for(int dy=-1;dy<=1;dy++){
                int ny=y+dy;
                if(nj>=0 &&nj<cols && ny>=0 && ny<cols){
                    ans=max(ans,f(row+1,nj,ny,grid));
                }
            }
        }
        ans+=grid[row][j];
        if(j!=y) ans+=grid[row][y];
        return dp[row][j][y]= ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        rows=grid.size();
        cols=grid[0].size();
        dp.assign(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        int i=0;
        int j=0;
        int y=cols-1;
        return f(i,j,y,grid);
    }
};