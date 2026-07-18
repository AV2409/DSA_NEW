class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            int from = it[0];
            int to = it[1];
            int wt = it[2];
            adj[from].push_back({to, wt});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        dist[src][0] = 0;
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;
        pq.push({0, src, 0});
        while (!pq.empty()) {
            auto [d, node, stops] = pq.top();
            pq.pop();
            if (node == dst)
                return d;

            if (d > dist[node][stops])
                continue;
            if (stops == k + 1)
                continue;

            for (auto [nei, wt] : adj[node]) {
                int newDist = d + wt;
                if (newDist < dist[nei][stops + 1]) {
                    dist[nei][stops + 1] = newDist;
                    pq.push({newDist, nei, stops + 1});
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i <= k + 1; i++)
            ans = min(ans, dist[dst][i]);

        return ans == 1e9 ? -1 : ans;
    }
};