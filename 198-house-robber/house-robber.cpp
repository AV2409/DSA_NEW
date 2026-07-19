class Solution {
public:
    vector<int>dp;
    int f(int i,vector<int>& nums){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int p=nums[i]+f(i-2,nums);
        int np=f(i-1,nums);

        return dp[i]= max(p,np);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,-1);
        return f(n-1,nums);
    }
};