class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        int i=1;
        vector<int>ans(n);
        for(auto it:mp){
            for(int idx:it.second){
                ans[idx]=i;
            }
            i++;
        }
        return ans;
    }
};