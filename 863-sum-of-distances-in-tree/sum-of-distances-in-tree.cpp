class Solution {
public:
    vector<int> res; 
    vector<int> subtree;
    vector<vector<int>> adj;

    // First DFS:
    // Computes:
    // 1. subtree size of every node
    // 2. res[0] = sum of distances from node 0
    void dfs1(int node, int parent, int depth) {
        subtree[node] = 1;
        res[0] += depth;

        for (int child : adj[node]) {
            if (child == parent) continue;

            dfs1(child, node, depth + 1);
            subtree[node] += subtree[child];
        }
    }

    // Second DFS:
    // Re-root the tree from parent -> child
    void dfs2(int node, int parent, int n) {
        for (int child : adj[node]) {
            if (child == parent) continue;

            res[child] = res[node] - subtree[child] + (n - subtree[child]);

            dfs2(child, node, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        res.assign(n, 0);
        subtree.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs1(0, -1, 0);
        dfs2(0, -1, n);

        return res;
    }
};