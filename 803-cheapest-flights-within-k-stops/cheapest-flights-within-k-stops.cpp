class Solution {
public:
    int n; // make n global inside class

    int getId(int node, int layer) {
        return node + layer * n;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        this->n = n;

        int totalNodes = n * (k + 2);
        vector<vector<pair<int,int>>> adj(totalNodes);

        // 🔗 Build layered graph
        for (auto &it : flights) {
            int u = it[0], v = it[1], w = it[2];

            for (int layer = 0; layer <= k; layer++) {
                int from = getId(u, layer);
                int to   = getId(v, layer + 1);

                adj[from].push_back({to, w});
            }
        }

        // 🚀 Dijkstra
        vector<int> dist(totalNodes, 1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int srcId = getId(src, 0);
        dist[srcId] = 0;
        pq.push({0, srcId});

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto [nei, wt] : adj[node]) {
                if (cost + wt < dist[nei]) {
                    dist[nei] = cost + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        // 🎯 Extract answer
        int ans = 1e9;
        for (int layer = 0; layer <= k+1; layer++) {
            ans = min(ans, dist[getId(dst, layer)]);
        }

        return ans == 1e9 ? -1 : ans;
    }
};