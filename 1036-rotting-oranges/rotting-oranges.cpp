class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }

        int time=0;
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        while(!q.empty() && fresh>0){
            int ss=q.size();
            for(int i=0;i<ss;i++){
                auto [x,y]=q.front();
                q.pop();

                for(int dir=0;dir<4;dir++){
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];

                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                        fresh--;
                    }
                }
            }
            time++;
        }
        if(fresh>0) return -1;
        return time;
    }
};