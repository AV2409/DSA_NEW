class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }

        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            pq;
        vector<vector<long long>> d(n, vector<long long>(k + 1, INT_MAX));
        pq.push({0, 0, k});

        while (!pq.empty()) {
            auto [dist, node, k2] = pq.top();
            pq.pop();
            if (node == n - 1)
                return dist;
            char lab = labels[node];

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                int neiLab = labels[adjNode];
                if (lab != neiLab) {
                    if (dist + wt < d[adjNode][k]) {
                        pq.push({dist + wt, adjNode, k});
                         d[adjNode][k]=dist+wt;
                    }
                } else if (lab == neiLab) {
                    if (k2 - 1 > 0)
                        if (dist + wt < d[adjNode][k2 - 1]) {
                            pq.push({dist + wt, adjNode, k2 - 1});
                            d[adjNode][k2-1]=dist+wt;
                        }
                }
            }
        }
        return -1;
    }
};