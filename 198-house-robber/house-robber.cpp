class Solution {
public:
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    dp[1] = nums[0];
    dp[0] = 0;
    for (int i = 2; i <= n; i++) {
        int op1 = dp[i-1];
        int op2 = nums[i-1] + dp[i - 2];
        dp[i]=max(op1,op2);
    }
    return dp[n];
}
};