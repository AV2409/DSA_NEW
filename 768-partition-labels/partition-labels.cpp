class Solution {
public:
    vector<int>merge(vector<vector<int>>&intervals){
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        // vector<vector<int>>ans;
        vector<int>res;
        int s1=intervals[0][0];
        int e1=intervals[0][1];
        for(int i=1;i<n;i++){
            int s2=intervals[i][0];
            int e2=intervals[i][1];

            if(s2<=e1){
                e1=max(e1,e2);
            }
            else{
                // ans.push_back({s1,e1});
                res.push_back(e1-s1+1);
                s1=s2;
                e1=e2;
            }
        }
        // ans.push_back({s1,e1});
        res.push_back(e1-s1+1);
        // return ans;
        return res;
    }
    vector<int> partitionLabels(string s) {
        vector<int>start(26,-1);
        vector<int>end(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++){
            int idx=s[i]-'a';
            if(start[idx]==-1) {
                start[idx]=i;
            }
            end[idx]=i;
        }

        vector<vector<int>>intervals;

        for(int i=0;i<26;i++){
            if(start[i]!=-1) intervals.push_back({start[i],end[i]});
        }

        return merge(intervals);
    }
};