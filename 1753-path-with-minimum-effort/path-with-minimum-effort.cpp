class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int>dx={0,0,1,-1};
        vector<int>dy={1,-1,0,0};
        int rows=heights.size();
        int cols=heights[0].size();
        vector<vector<int>>dist(rows,vector<int>(cols,1e9));
        dist[0][0]=0;
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        
        while(!pq.empty()){
            auto [eff,x,y]=pq.top();
            pq.pop();
            
            if(eff>dist[x][y]) continue;

            for(int dir=0;dir<4;dir++){
                int nx=x+dx[dir];
                int ny=y+dy[dir];

                if(nx>=0 && ny>=0 && nx<rows && ny<cols){
                    int newEff=max(eff,abs(heights[nx][ny]-heights[x][y]));
                    if(newEff<dist[nx][ny]){
                        dist[nx][ny]=newEff;
                        pq.push({newEff,nx,ny});
                    }
                }
            }
        }
        return dist[rows-1][cols-1];

    }
};