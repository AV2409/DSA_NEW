class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses,0);
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
            indeg[u]++;
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(!indeg[i]){
                q.push(i);
            }
        }

        vector<int>topo;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(int adjNode:adj[node]){
                indeg[adjNode]--;
                if(!indeg[adjNode]) q.push(adjNode);
            }
            
        }
        return topo.size()==numCourses;
    }
};