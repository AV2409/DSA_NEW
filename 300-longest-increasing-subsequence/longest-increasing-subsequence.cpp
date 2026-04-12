class Solution {
public:
    
    int f(int idx,int prev,vector<int>& nums,vector<vector<int>>&dp){
        if(idx==nums.size()) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int op1=f(idx+1,prev,nums,dp);
        int op2=0;
        if(prev==-1 || nums[idx]>nums[prev]) op2=1+f(idx+1,idx,nums,dp);

        return dp[idx][prev+1]=max(op1,op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        f(0,-1,nums,dp);
        return dp[0][0];
    }
};