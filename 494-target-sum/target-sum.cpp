class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,vector<int>& nums, int target){
        if(i<0){
            if(target==0) return 1;
            return 0;
        }

        if(dp[i][target]!=-1) return dp[i][target];

        int np=f(i-1,nums,target);
        int p=0;
        if(target>=nums[i]) p=f(i-1,nums,target-nums[i]);
        return dp[i][target]= p+np;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        if(abs(target)>sum) return 0;
        int req=sum+target;
        if(req & 1) return 0;
        req/=2;
        int n=nums.size();
        dp.assign(n,vector<int>(req+1,-1));
        
        return f(n-1,nums,req);
        
    }
};