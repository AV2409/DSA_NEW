class Solution {
public:
    vector<int> dp;
    int f(int target, vector<int>& nums) {
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for(int x:nums){
            if(x<=target) ans+=f(target-x,nums);
        }
        return dp[target]= ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        dp.assign(target + 1, -1);
        int x = f(target, nums);
        return x;
    }
};