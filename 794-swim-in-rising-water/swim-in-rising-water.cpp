class Solution {
public:
//minimize max value of a path
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=grid[0][0];
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({dist[0][0],0,0});
        vector<int>dx={0,0,1,-1};
        vector<int>dy={1,-1,0,0};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int maxi=it[0];
            int x=it[1];
            int y=it[2];
            if(maxi > dist[x][y])
                continue;

            if(x==n-1 && y==n-1) return maxi;

            for(int dir=0;dir<4;dir++){
                int nx=x+dx[dir];
                int ny=y+dy[dir];

                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    int newMaxi=max(maxi,grid[nx][ny]);
                    if(newMaxi<dist[nx][ny]){
                        dist[nx][ny]=newMaxi;
                        pq.push({newMaxi,nx,ny});
                    }
                }
            }
            
        }
        return 0;
    }
};