class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            mp[num].push_back(i);
        }

        for(auto it:mp){
            if(it.second.size()>1){
                vector<int>v=it.second;
                int ss=v.size();
                for(int i=1;i<ss;i++){
                    if(v[i]-v[i-1]<=k) return true;
                }
            }
        }
        return false;
    }
};