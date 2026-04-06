class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int c, vector<int>& colors) {
        colors[node] = c;
        int nextC;
        if(c==1) nextC=2;
        if(c==2) nextC=1;

        for(int nei:graph[node]){
            if(colors[nei]==0){
                if(dfs(graph,nei,nextC,colors)==false) return false;
            }
            else{
                if(colors[nei]==c) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0) {
                if (dfs(graph, i, 1, colors) == false)
                    return false;
            }
        }
        return true;
    }
};