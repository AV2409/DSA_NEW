class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        vector<vector<int>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            dist[u][v] = min(dist[u][v], wt);
            dist[v][u] = min(dist[v][u], wt);
        }

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (int via = 0; via < n; via++) {
            for (int from = 0; from < n; from++) {
                for (int to = 0; to < n; to++) {
                    if(dist[from][via]==1e9||dist[via][to]==1e9) continue;
                    dist[from][to]=min(dist[from][to],dist[from][via]+dist[via][to]);
                }
            }
        }

        int mini=n+1;
        int ans=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) cnt++;
            }
            if(cnt<=mini){
                mini=cnt;
                ans=i;
            }
        }
        return ans;
    }
};