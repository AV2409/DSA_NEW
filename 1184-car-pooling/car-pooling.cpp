class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>dist(1001);

        for(auto trip:trips){
            int pass=trip[0];
            int from=trip[1];
            int to=trip[2];

            dist[from]+=pass;
            dist[to]-=pass;
        }
        int maxi=dist[0];
        for(int i=1;i<1001;i++){
            dist[i]+=dist[i-1];
            maxi=max(maxi,dist[i]);
        }
        if(maxi<=capacity) return true;
        return false;
    }
};