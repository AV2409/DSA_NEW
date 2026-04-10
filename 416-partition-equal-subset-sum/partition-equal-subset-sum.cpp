class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int x = 1; x <= sum; x++) {
                // not pick
                bool op1 = dp[i - 1][x];
                bool op2 = false;

                if (x - arr[i - 1] >= 0)
                    op2 = dp[i - 1][x - arr[i - 1]];

                dp[i][x] = op1 || op2;
            }
        }

        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return false;
        sum/=2;
        return isSubsetSum(nums,sum);
    }
};