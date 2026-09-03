class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<int>dx={0,0,1,-1};
        vector<int>dy={1,-1,0,0};
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=grid[0][0];
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({grid[0][0],0,0});
        
        while(!pq.empty()){
            auto [eff,x,y]=pq.top();
            pq.pop();
            
            if(eff>dist[x][y]) continue;

            for(int dir=0;dir<4;dir++){
                int nx=x+dx[dir];
                int ny=y+dy[dir];

                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    int newEff=max(eff,grid[nx][ny]);
                    if(newEff<dist[nx][ny]){
                        dist[nx][ny]=newEff;
                        pq.push({newEff,nx,ny});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};