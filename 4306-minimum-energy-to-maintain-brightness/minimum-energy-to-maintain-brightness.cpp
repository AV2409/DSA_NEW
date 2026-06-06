class Solution {
public:
    
    long long mergeOverlapping(vector<vector<int>>& intervals){
        int st=intervals[0][0];
        int end=intervals[0][1];
        
        int res=0;
        for(auto it:intervals){
            int s2=it[0];
            int e2=it[1];

            if(s2<=end){
                end=max(end,e2);
                continue;
            }
            res+=end-st+1;
            st=s2;
            end=e2;
        }
        res+=end-st+1;
        return res;
    }
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        long long time=mergeOverlapping(intervals);
        long long x;
        x=brightness/3;
        if(brightness%3) x++;

        return x*time;
    }
};