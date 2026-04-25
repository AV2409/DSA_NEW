class Solution {
public:
    int cnt = 0;

    bool isConnected(vector<int>& subset, vector<vector<int>>& adj, int n) {
        if (subset.empty())
            return false;

        unordered_set<int> nodes(subset.begin(), subset.end());

        vector<int> vis(n, 0);
        queue<int> q;

        q.push(subset[0]);
        vis[subset[0]] = 1;

        int reached = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            reached++;

            for (int v : adj[u]) {
                if (nodes.count(v) && !vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return reached == subset.size();
    }
    void f(int i, vector<int>& nums, int sum, vector<int>& subset, vector<vector<int>>& adj) {
        if (i == nums.size()) {
            if (!subset.empty() && sum % 2 == 0) {
                if (isConnected(subset, adj, nums.size()))
                    cnt++;
            }
            return;
        }

        f(i + 1, nums, sum, subset, adj);

        subset.push_back(i);
        f(i + 1, nums, sum + nums[i], subset, adj);
        subset.pop_back();
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> subset;
        f(0, nums, 0, subset, adj);
        return cnt;
    }
};