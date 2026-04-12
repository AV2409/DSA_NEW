class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if(dp[j]+1>dp[i]){
                        dp[i] = max(dp[i], 1 + dp[j]);
                        count[i]=count[j];
                    }

                    else if(dp[j]+1==dp[i]){
                        dp[i] = max(dp[i], 1 + dp[j]);
                        count[i]+=count[j];
                    }

                    
                }
            }
            ans = max(ans, dp[i]);
        }

        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==ans) res+=count[i];
        }
        return res;
    }
};