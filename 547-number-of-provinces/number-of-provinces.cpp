class Solution {
public:
    void dfs_traversal(vector<vector<int>> &isConnected, int node,
                       vector<int>& visited, int n) {
        visited[node] = 1;
        for (int i = 0; i < n; i++) {
            if ((isConnected[node][i] == 1) && (!visited[i]))
                dfs_traversal(isConnected, i, visited, n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs_traversal(isConnected, i, visited, n);
                cnt++;
            }
        }
        return cnt;
    }
};