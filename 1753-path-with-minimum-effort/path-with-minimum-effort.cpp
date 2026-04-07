class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        //diff,x,y
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {-1, 1, 0, 0};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        dist[0][0]=0;
        while(!pq.empty()){
            auto [diff,x,y]=pq.top();
            pq.pop();

            if(x==n-1 && y==m-1) return diff;

            for(int d=0;d<4;d++){
                int nx=x+dx[d];
                int ny=y+dy[d];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    int edge = abs(heights[nx][ny] - heights[x][y]);
                    int newEffort = max(diff, edge);

                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};