class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long pre=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            pre+=nums[i];
            int rem=(pre%k+k)%k;

            if(mp.count(rem)){
                if(i-mp[rem]>=2) return true;
            }
            else mp[rem]=i;
        }
        return false;
    }
};