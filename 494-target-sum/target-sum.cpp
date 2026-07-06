class Solution {
public:
    vector<vector<int>>dp;
    int f(int i, int sum,vector<int>& nums){
        if(i<0) return sum==0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int np=f(i-1,sum,nums);
        int p=0;
        if(nums[i]<=sum) p=f(i-1,sum-nums[i],nums);
        return dp[i][sum]= p+np;
    }

    int perfectSum(vector<int>& nums,int sum){
        int n=nums.size();
        dp.assign(n,vector<int>(sum+1,-1));
        return f(n-1,sum,nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        sum-=target;
        if ((sum) < 0 || (sum) % 2 != 0) {
            return 0;
        }
        return perfectSum(nums, sum/2);
    }
};