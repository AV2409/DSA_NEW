class Solution {
public:

    int f(int idx,int time,vector<int>& sat,vector<vector<int>>&dp){
        if(idx==sat.size()) return 0;
        if(dp[idx][time]!=-1) return dp[idx][time];
        int take = sat[idx]*time + f(idx+1,time+1,sat,dp);

        int skip = f(idx+1,time,sat,dp);

        return dp[idx][time] = max(take,skip);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,1,satisfaction,dp);
    }
};