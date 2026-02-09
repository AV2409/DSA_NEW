class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp) {
        if (i == 0)
            return nums[i];
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int op1;
        int op2;

        op1 = f(i - 1, nums, dp);
        op2 = nums[i] + f(i - 2, nums, dp);

        return dp[i] = max(op1, op2);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        return f(n - 1, nums, dp);
    }
};