class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int dp[n + 1][2];
        int ans=arr[0];
        dp[0][0]=-1e9;
        dp[0][1]=-1e9;
        for (int i = 1; i <= n; i++) {

            int op1 = arr[i - 1];              
            int op2 = arr[i - 1] + dp[i - 1][0]; 
            dp[i][0] = max(op1, op2);

    
            dp[i][1] = max(dp[i - 1][0],          
                           arr[i - 1] + dp[i - 1][1] 
            );
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        return ans;
    }
};