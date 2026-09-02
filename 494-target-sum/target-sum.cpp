class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,vector<int>& nums,int sum){
        if(i<0){
            return sum==0;
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        int np=f(i-1,nums,sum);
        int p=false;
        if(sum>=nums[i]) p=f(i-1,nums,sum-nums[i]);
        return dp[i][sum]= p+np;
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