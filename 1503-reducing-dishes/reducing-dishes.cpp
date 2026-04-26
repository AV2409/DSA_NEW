class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(), satisfaction.end());

        int n=satisfaction.size();

        vector<vector<int>> dp(n+1,vector<int>(n+2,0));

        for(int i=n-1;i>=0;i--){
            for(int time=n;time>=1;time--){
                int take=satisfaction[i]*time + dp[i+1][time+1];
                int skip=dp[i+1][time];
                dp[i][time]=max(take,skip);
            }
        }

        return dp[0][1];
    }
};