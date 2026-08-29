class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int st=intervals[0][0];
        int end=intervals[0][1];

        vector<vector<int>>ans;

        for(int i=1;i<n;i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(s<=end){
                end=max(end,e);
            }
            else{
                ans.push_back({st,end});
                st=s;
                end=e;
            }
        }
        ans.push_back({st,end});
        return ans;

    }
};