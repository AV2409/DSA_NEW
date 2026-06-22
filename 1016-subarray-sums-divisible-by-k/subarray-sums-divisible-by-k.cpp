class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int pre=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            int rem = ((pre % k) + k) % k;
            if(mp.count(rem)) ans+=mp[rem];

            mp[rem]++;
        }
        return ans;
    }
};