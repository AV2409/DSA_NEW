class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;

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
            ans.push_back({st,end});
            st=s2;
            end=e2;
        }
        ans.push_back({st,end});
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};