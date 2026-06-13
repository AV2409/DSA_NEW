class Solution {
public:

    bool static comp(vector<int>& a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        if(n==1) return 0;
        sort(intervals.begin(),intervals.end(),comp);

        if(n==2){
            if(intervals[0][1]>intervals[1][0]) return 1; 
            else return 0;
        } 
        int done=1;
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=end) {
                done++;
                end=intervals[i][1];
            }
        }
        return n-done;
    }
};