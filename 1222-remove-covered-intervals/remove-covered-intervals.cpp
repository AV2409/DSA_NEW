class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>=b[1];
    }
    vector<vector<int>>ans;
    int cnt=1;
    void merge(vector<vector<int>>& intervals){
        int n=intervals.size();
        int s1=intervals[0][0];
        int e1=intervals[0][1];
        // ans.push_back({s1,e1});
        for(int i=1;i<n;i++){
            int s2=intervals[i][0];
            int e2=intervals[i][1];

            if(s2>=s1 && e2<=e1){
                continue;
            }
            else{
                // ans.push_back({s2,e2});
                cnt++;
                s1=s2;
                e1=e2;
            }
        }
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        merge(intervals);
        // for(auto it:ans){
        //     cout<<it[0]<<"-"<<it[1]<<", ";
        // }
        return cnt;
    }
};