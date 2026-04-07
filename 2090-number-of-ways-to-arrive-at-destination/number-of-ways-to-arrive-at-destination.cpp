class Solution {
public:
int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long, int>>> adj(n);
        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, 1e18);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto [nei, wt] : adj[node]) {
                if(d+wt==dist[nei]) ways[nei] = (ways[nei] + ways[node]) % MOD;
                else if (d + wt < dist[nei]) {
                    dist[nei] = d + wt;
                    ways[nei]=ways[node];
                    pq.push({dist[nei], nei});
                }
            }
        }
        
        return ways[n-1]%MOD;
    }
};