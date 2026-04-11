class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2));
        //j=0 not bought
        //j=1 bought
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j==1){
                    int op1=dp[i+1][1];
                    int op2=prices[i]+dp[i+1][0];
                    dp[i][j]=max(op1,op2);
                }

                if(j==0){
                    int op1=dp[i+1][0];
                    int op2=dp[i+1][1]-prices[i];
                    dp[i][j]=max(op1,op2);
                }
            }
        }

        return dp[0][0];
    }
};