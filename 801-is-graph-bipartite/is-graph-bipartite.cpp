class Solution {
public:
    bool bfs(int i, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[i] = col;
        queue<pair<int, int>> q;
        q.push({i, col});

        while (!q.empty()) {
            pair<int, int> p = q.front();
            int node = p.first;
            int c = p.second;
            q.pop();

            for (int it : graph[node]) {
                if (color[it] == -1) {
                    q.push({it, !c});
                    color[it] = !c;
                } else if (color[it] == c) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (bfs(i, 0, color, graph) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};