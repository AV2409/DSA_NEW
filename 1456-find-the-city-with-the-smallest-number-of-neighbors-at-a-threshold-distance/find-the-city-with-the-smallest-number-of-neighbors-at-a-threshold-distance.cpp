class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // can also be done while initialization
                    if (i == j) {
                        dist[i][j] = 0;
                        continue;
                    }

                    if (dist[i][via] == 1e8 || dist[via][j] == 1e8)
                        continue;
                    dist[i][j] = min(dist[i][j], (dist[i][via] + dist[via][j]));
                }
            }
        }

        int city = 0;
        int minCity = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    city++;
                }
            }
            if (city <= minCity) {
                minCity = city;
                ans = i;
            }
            city = 0;
        }
        return ans;
    }
};