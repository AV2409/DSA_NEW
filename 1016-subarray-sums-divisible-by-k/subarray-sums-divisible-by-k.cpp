class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int cnt=0;
        int pre=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            int rem = (pre % k + k) % k; 
            if(mp.find(rem)!=mp.end()) cnt+=mp[rem];

            mp[rem]++;
        }
        return cnt;
    }
};