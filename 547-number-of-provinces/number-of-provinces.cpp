class Solution {
public:
    void dfs_traversal(vector<int> adj[], int node, vector<int>& visited) {
        visited[node] = 1;
        for (int i : adj[node]) {
            if (!visited[i])
                dfs_traversal(adj, i, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((isConnected[i][j] == 1) && i != j)
                    adj[i].push_back(j);
            }
        }

        cout << n << " " << m << endl;

        for (int i = 0; i < n; i++) {
            cout << "Node " << i << ": ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << endl;
        }

        vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs_traversal(adj, i, visited);
                cnt++;
            }
        }
        return cnt;
    }
};