class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> deg(n);
        vector<vector<int>> adj(n);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            deg[u]++;
            deg[v]++;
        }
        queue<int> q;
        int nodes = n;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                q.push(i);
                vis[i] = true;
            }
        }

        while (!q.empty() && nodes > 2) {
            int ss = q.size();
            for (int i = 0; i < ss; i++) {
                int node = q.front();
                q.pop();
                nodes--;

                for (int adjNode : adj[node]) {
                    deg[adjNode]--;
                    if (deg[adjNode] == 1)
                        q.push(adjNode);
                }
            }
        }
        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};