class Solution {
public:
    vector<pair<int,int>>dir={{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
    int n;
    bool dfs(int i,int j,vector<vector<int>>& grid){
        if(grid[i][j]==((n*n)-1)) return true;

        for(auto [dx,dy]:dir){
            int nx=i+dx;
            int ny=j+dy;

            if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==1+grid[i][j]){
                if(dfs(nx,ny,grid)) return true;
            }
        } 
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        n=grid.size();
        if(grid[0][0]!=0) return false;
        return dfs(0,0,grid);
    }
};