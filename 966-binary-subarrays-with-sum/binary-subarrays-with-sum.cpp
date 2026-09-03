class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int req=sum-goal;
            ans+=mp[req];
            mp[sum]++;
        }
        return ans;
    }
};