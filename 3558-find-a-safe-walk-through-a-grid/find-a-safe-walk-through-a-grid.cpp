class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));


        pq.push({grid[0][0],0,0});
        dist[0][0]=0;
        vector<int>dx={0,0,1,-1};
        vector<int>dy={1,-1,0,0};
        while(!pq.empty()){
            auto [d,x,y]=pq.top();
            pq.pop();
            if(x==m-1 && y==n-1){
                if(health>dist[x][y]) return true;
                return false;
            }

            for(int dir=0;dir<4;dir++){
                int nx=x+dx[dir];
                int ny=y+dy[dir];

                if(nx>=0 && ny>=0 && nx<m && ny<n && d+grid[nx][ny]<dist[nx][ny]){
                    dist[nx][ny]=d+grid[nx][ny];
                    pq.push({dist[nx][ny],nx,ny});
                }
            }
        }
        return false;
    }
};