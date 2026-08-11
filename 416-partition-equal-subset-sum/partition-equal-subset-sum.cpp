class Solution {
public:
    vector<vector<int>>dp;
    bool f(int i,int sum,vector<int>& nums){
        if(sum==0) return true;
        if(i<0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool np=f(i-1,sum,nums);
        bool p=false;
        if(sum>=nums[i]) p=f(i-1,sum-nums[i],nums);
        return dp[i][sum] = p||np;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2) return false;
        sum/=2;
        dp.assign(n,vector<int>(sum+1,-1));
        return f(n-1,sum,nums);
    }
};