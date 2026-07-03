class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&path){
        path[node]=1;
        for(int adjNode:adj[node]){
            if(!path[adjNode]){
                if(dfs(adjNode,adj,path)) return true;
            }
            else if(path[adjNode]==1) return true;
        }
        path[node]=2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        vector<int>path(numCourses);

        for(int i=0;i<numCourses;i++){
            if(!path[i]){
                if(dfs(i,adj,path)) return false;
            }
        }
        return true;
    }
};