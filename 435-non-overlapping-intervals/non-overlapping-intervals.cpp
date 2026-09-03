class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int end=intervals[0][1];
        int done=1;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            int s=intervals[i][0];
            int e=intervals[i][1];

            if(s>=end){
                done++;
                end=e;
            }
        }
        return n-done;

    }
};