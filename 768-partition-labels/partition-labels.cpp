class Solution {
public:
    vector<int>mergeIntervals(vector<vector<int>>&intervals){
        sort(intervals.begin(),intervals.end());

        int st=intervals[0][0];
        int end=intervals[0][1];
        int n=intervals.size();
        vector<int>ans;
        for(int i=1;i<n;i++){
            int s=intervals[i][0];
            int e=intervals[i][1];

            if(s<=end){
                end=max(e,end);
            }
            else{
                ans.push_back(end-st+1);
                st=s;
                end=e;
            }
        }
        ans.push_back(end-st+1);
        return ans;
    }
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            if(!mp.count(s[i])){
                mp[s[i]].first=i;
            }
            mp[s[i]].second=i;
        }
        vector<vector<int>>intervals;
        for(auto it:mp){
            intervals.push_back({it.second.first,it.second.second});
        }

        vector<int>ans=mergeIntervals(intervals);
        return ans;
    }
};