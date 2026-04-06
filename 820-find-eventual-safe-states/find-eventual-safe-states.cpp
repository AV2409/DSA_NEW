class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>adj(V);
        vector<int>indeg(V);
        for(int node=0;node<V;node++){
            for(int nei:graph[node]){
                adj[nei].push_back(node);
                indeg[node]++;
            }
        }  

        queue<int>q;      
        
        for(int i=0;i<V;i++){
            if(indeg[i]==0) q.push(i); 
        }
        vector<bool>flag(V);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            flag[node]=true;

            for(int nei:adj[node]){
                indeg[nei]--;
                if(indeg[nei]==0) q.push(nei);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(flag[i]) ans.push_back(i); 
        }
        return ans;
    }
};