class Solution {
public:
    int m;
    int n;
    vector<vector<int>>dp;

    int f(int i,int j,vector<vector<int>>& grid){
        if(i==m-1 && j==n-1){
            if(grid[i][j]<0) return abs(grid[i][j])+1;
            else return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int down=INT_MAX;
        int right=INT_MAX;

        if(i+1<m) down=f(i+1,j,grid);
        if(j+1<n) right=f(i,j+1,grid);

        int res=min(down,right)-grid[i][j];
        if(res<=0) return dp[i][j]= 1;
        return dp[i][j]= res;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m=dungeon.size();
        n=dungeon[0].size();
        dp.assign(m,vector<int>(n,-1));
        return f(0,0,dungeon);

    }
};