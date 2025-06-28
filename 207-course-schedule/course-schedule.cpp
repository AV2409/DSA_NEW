class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<int> adj[numCourses];

        for (int i = 0; i < m; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        vector<int> indeg(numCourses, 0);
        for (int i = 0; i < m; i++) {
            int v = prerequisites[i][1];
            indeg[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int ele = q.front();
            q.pop();
            ans.push_back(ele);

            for (int it : adj[ele]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        return (ans.size() == numCourses);
    }
};