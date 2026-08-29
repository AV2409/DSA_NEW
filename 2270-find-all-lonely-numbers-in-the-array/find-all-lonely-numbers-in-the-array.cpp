class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }

        vector<int>ans;
        for(int x:nums){
            if(mp[x]>1 || (mp.count(x-1))||(mp.count(x+1))) continue;
            ans.push_back(x);
        }
        return ans;
    }
};