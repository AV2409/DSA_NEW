class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        int m = flights.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];

            adj[u].push_back({v, cost});
        }

        //{stops,{node,stops}}

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int d = it.second.second;

            if (stops <= k) {
                for (auto it : adj[node]) {
                    int adjNode = it.first;
                    int pathCost = it.second;

                    if (pathCost + d < dist[adjNode]) {
                        dist[adjNode] = pathCost + d;
                        q.push({stops + 1, {adjNode, dist[adjNode]}});
                    }
                }
            }
        }
        if (dist[dst] == 1e9) {
            return -1;
        }
        return dist[dst];
    }
};