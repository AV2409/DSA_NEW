class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, vector<int>& arr, int target) {
        // if(target==0) return 1;
        if (i < 0)
            return target == 0;
        if (dp[i][target] != -1)
            return dp[i][target];
        int np = f(i - 1, arr, target);
        int p = 0;
        if (target - arr[i] >= 0)
            p = f(i - 1, arr, target - arr[i]);

        return dp[i][target] = p + np;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        dp.assign(n, vector<int>(target + 1, -1));
        return f(n - 1, arr, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(target>sum) return 0;
        int reqSum=sum-target;
        if((reqSum)%2) return 0;
        reqSum/=2;
        
        return perfectSum(nums,reqSum);
        
    }
};