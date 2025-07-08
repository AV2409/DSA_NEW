class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
        vector<int> ans(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        q.push({0, src});
        ans[src] = 0;
        while (!q.empty()) {
            pair<int, int> p = q.top();
            q.pop();
            int node = p.second;
            int dis = p.first;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int pathCost = it.second;

                if (dis + pathCost < ans[adjNode]) {
                    q.push({dis + pathCost, adjNode});
                    ans[adjNode] = dis + pathCost;
                }
            }
        }
        return ans;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<vector<int>> dist(n);

        for (int i = 0; i < n; i++) {
            dist[i] = dijkstra(n, adj, i);
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
            city=0;
        }
        return ans;
    }
};