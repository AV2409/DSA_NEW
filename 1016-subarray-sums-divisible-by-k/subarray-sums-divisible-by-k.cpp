class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int s=0;
        mp[0]=1;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s+=nums[i];
            int req=(s%k+k)%k;
            if(mp.count(req)) ans+=mp[req];
            mp[req]++;
        }
        return ans;
    }
};