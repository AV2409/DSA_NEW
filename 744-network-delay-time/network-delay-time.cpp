class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto it : times) {
            int from = it[0];
            int to = it[1];
            int wt = it[2];
            adj[from].push_back({to, wt});
        }

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>>pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto [nei, wt] : adj[node]) {
                int newDist = d + wt;
                if (newDist < dist[nei]) {
                    dist[nei] = newDist;
                    pq.push({newDist, nei});
                }
            }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++)
            ans = max(ans, dist[i]);

        return ans == 1e9 ? -1 : ans;
    }
};