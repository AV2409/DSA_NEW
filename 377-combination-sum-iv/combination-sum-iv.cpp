class Solution {
public:
    vector<int>dp;
    int f(vector<int>& nums, int target) {
        if (target == 0)
            return 1;

        if(dp[target]!=-1) return dp[target];
        int ans=0;
        for (int i = 0; i < nums.size(); i++) {
            int p = 0;
            if (target >= nums[i])
                p = f(nums, target - nums[i]);
            ans+= p;
        }
        return dp[target]= ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        dp.assign(target+1,-1);
        return f(nums, target);
    }
};