class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        long long rating=0;
        for(int i=0;i<m;i++) rating+=units[i][0];
        if(n==1) {
            return rating;
        }

        int secMinRow=-1;
        int secMin=INT_MAX;
        int globalMin=INT_MAX;
        for (auto& row : units) {
            sort(row.begin(), row.end());
        }
        for(int i=0;i<m;i++){
            if(units[i][1]<secMin){
                secMin=units[i][1];
                secMinRow=i;
            }
            globalMin=min(globalMin,units[i][0]);
        }

        rating =0; 

        for(int i=0;i<m;i++){
            if(i==secMinRow) continue;
            rating+=units[i][1];
        }

        return rating + globalMin;
    }
};