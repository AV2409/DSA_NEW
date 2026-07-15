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
        
        for(int i=1;i<n;i++){
            int newSt=intervals[i][0];
            int newEnd=intervals[i][1];

            if(newSt<=end){
                end=max(end,newEnd);
            }
            else{
                ans.push_back({st,end});
                st=newSt;
                end=newEnd;
            }
        }
        ans.push_back({st,end});
        return ans;
    }
};