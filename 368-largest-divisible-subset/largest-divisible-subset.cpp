class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> par(n, -1);

        int lis = 1;
        int idx=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {

                if (nums[i]%nums[j]==0) {
                    if (1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        par[i] = j;
                    }
                }
            }
            if(dp[i]>lis){
                idx=i;
                lis = max(lis, dp[i]);
            }
        }
        vector<int>ans;
        ans.push_back(nums[idx]);
        while(par[idx]!=-1){
            idx=par[idx];
            ans.push_back(nums[idx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};