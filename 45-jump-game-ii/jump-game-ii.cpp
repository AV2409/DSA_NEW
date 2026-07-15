class Solution {
public:
    int n;
    vector<int>dp;
    int f(int idx,vector<int>& nums){
        if(idx>=n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int x=nums[idx];
        int ans=1e9;
        for(int i=1;i<=x;i++){
            ans=min(ans,1+f(idx+i,nums));
        }
        return dp[idx]= ans;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        dp.assign(n,-1);
        return f(0,nums);
    }
};