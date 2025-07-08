class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int del = it[2];

            adj[u].push_back({v, del});
        }
        vector<int> delay(n+1, 1e8);
        delay[k]=0;
        delay[0]=-1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, k});
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int del = p.first;
            int node = p.second;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int d = it.second;

                if (d + del < delay[adjNode]) {
                    delay[adjNode] = d + del;
                    q.push({delay[adjNode], adjNode});
                }
            }
        }

        int ans = 0;
        for (int i : delay) {
            if (i == 1e8) {
                return -1;
            }
            ans = max(ans, i);
        }
        return ans;
    }
};