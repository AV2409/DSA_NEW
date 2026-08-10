class Solution {
public:
    vector<int>dx={0,0,1,-1};
    vector<int>dy={1,-1,0,0};
    int m;
    int n;
    void dfs(int x,int y,vector<vector<char>>& grid){
        grid[x][y]='0';

        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];

            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]=='1'){
                dfs(nx,ny,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(grid[x][y]=='1'){
                    ans++;
                    dfs(x,y,grid);
                }
            }
        }
        return ans;
    }
};