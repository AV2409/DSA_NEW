class Solution {
public:
    vector<int>cols;
    bool dfs(int node,int col,vector<vector<int>>& adj){
        cols[node]=col;
        int newCol=1-col;

        for(int nei:adj[node]){
            if(cols[nei]==-1){
                if(dfs(nei,newCol,adj)==false) return false;
            }
            else if(cols[nei]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        cols.assign(n,-1);

        for(int i=0;i<n;i++){
            if(cols[i]==-1){
                if(dfs(i,0,graph)==false) return false;
            }
        }
        return true;
        
    }
};