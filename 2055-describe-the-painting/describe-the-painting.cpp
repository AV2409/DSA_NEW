class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<int,long long> mp;

        for(auto &s : segments){
            mp[s[0]] += s[2];
            mp[s[1]] -= s[2];
        }
        vector<vector<long long>> ans;
        long long currSum = 0;
        int prev=0;
        for (auto &it : mp) {
            int pos=it.first;
            long long delta=it.second;
            if(currSum > 0){
                ans.push_back({(long long)prev, (long long)pos, currSum});
            }
            currSum += delta;
            prev = pos;
        }
        return ans;
    }
};