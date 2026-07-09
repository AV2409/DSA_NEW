class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int prev,vector<int>& nums){
        if(i==nums.size()) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        //dont pick
        int op1=f(i+1,prev,nums);
        int op2=0;
        if(prev==-1||nums[prev]<nums[i]) op2=1+f(i+1,i,nums);

        return dp[i][prev+1]= max(op1,op2);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,vector<int>(n+1,-1));
        return f(0,-1,nums);
    }
};