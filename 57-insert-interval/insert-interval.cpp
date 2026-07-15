class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int s=newInterval[0];
        int e=newInterval[1];
        int n=intervals.size();
        bool isIns=false;
        for(int i=0;i<n;i++){
            int st=intervals[i][0];
            int end=intervals[i][1];

            if(end<s){
                ans.push_back({st,end});
            }
            else if(st>e){
                if(!isIns){
                    ans.push_back({s,e});
                    isIns=true;
                }
                ans.push_back({st,end});
            }
            else{
                s=min(st,s);
                e=max(e,end);
            }
        }

        if(!isIns) ans.push_back({s,e});
        return ans;
    }
};