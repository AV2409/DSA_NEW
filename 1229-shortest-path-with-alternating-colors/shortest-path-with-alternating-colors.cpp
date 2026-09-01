class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {

        vector<vector<int>> adjRed(n);
        vector<vector<int>> adjBlue(n);
        for (auto it : redEdges) {
            int u = it[0];
            int v = it[1];

            adjRed[u].push_back(v);
        }

        for (auto it : blueEdges) {
            int u = it[0];
            int v = it[1];

            adjBlue[u].push_back(v);
        }

        vector<vector<int>> vis(n, vector<int>(2, 0));
        vector<int> dist(n, 1e9);

        dist[0] = 0;

        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});

        int d = 1;
        vis[0][0] = 1;
        vis[0][1] = 1;
        while (!q.empty()) {
            int ss = q.size();
            while (ss--) {
                auto [node, col] = q.front();
                q.pop();

                int red = 1 - col;
                int blue = 1 - red;
                // we need next blue
                if (red) {
                    for (int nei : adjBlue[node]) {
                        if (!vis[nei][1]) {
                            dist[nei] = min(d,dist[nei]);
                            q.push({nei,1});
                            vis[nei][1] = 1;
                        }
                    }
                }
                // we need red
                else if (blue) {
                    for (int nei : adjRed[node]) {
                        if (!vis[nei][0]) {
                            dist[nei] = min(d,dist[nei]);
                            q.push({nei,0});
                            vis[nei][0] = 1;
                        }
                    }
                }
            }
            d++;
        }

        for (int i = 0; i < n; i++) {
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }
};