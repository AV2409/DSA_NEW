class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>indeg(n);
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                adj[x].push_back(i);
                indeg[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans.push_back(node);
            for(int nei:adj[node]){
                indeg[nei]--;
                if(indeg[nei]==0) q.push(nei);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};