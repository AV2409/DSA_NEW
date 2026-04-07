class Solution {
public:
vector<int>dx={0,0,-1,1};
vector<int>dy={-1,1,0,0};
int rows;
int cols;
    void dfs_helper(vector<vector<int>>& grid,int x,int y,int &ans){
        ans++;
        grid[x][y]=0;
        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];

            if(nx>=0 && ny>=0 && nx<rows && ny<cols && grid[nx][ny]==1){
                dfs_helper(grid,nx,ny,ans);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        rows=n;
        cols=m;
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int ans=0;
                    dfs_helper(grid,i,j,ans);
                    maxi=max(ans,maxi);
                }
            }
        }
        return maxi;
    }
};