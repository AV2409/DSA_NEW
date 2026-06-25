class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            sum=sum%p;
        }
        if (sum == 0) return 0;
        long long pre=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int len=INT_MAX;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            int rem=(pre%p+p)%p;
            int req=(rem-sum+p)%p;
            if(mp.count(req)){
                len=min(len,i-mp[req]);
            }
            mp[rem]=i;

        }
        if(len==n) return -1;
        return len;
    }
};