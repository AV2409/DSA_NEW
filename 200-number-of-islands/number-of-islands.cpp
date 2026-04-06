class Solution {
public:
vector<int>dx={0,0,-1,1};
vector<int>dy={-1,1,0,0};
int rows;
int cols;
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j){
        vis[i][j]=1;
        
        for(int dir=0;dir<4;dir++){
            int nx=i+dx[dir];
            int ny=j+dy[dir];

            if(nx>=0 && ny>=0 && nx<rows && ny<cols && !vis[nx][ny] && grid[nx][ny]=='1'){
                dfs(grid,vis,nx,ny);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        rows=m;
        cols=n;
        int cnt=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};