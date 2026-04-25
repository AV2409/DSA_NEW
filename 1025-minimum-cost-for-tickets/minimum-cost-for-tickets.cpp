class Solution {
public:
    int find(int idx,vector<int>& days,int package){
        int currDay = days[idx];
        int i=idx;
        int n=days.size();
        while(i<n && days[i]<currDay+package){
            i++;
        }
        return i;
    }
    int f(int idx, vector<int>& days, vector<int>& costs,vector<int>& dp) {
        if (idx >= days.size())
            return 0;

        // 1day
        if(dp[idx]!=-1) return dp[idx];
        int op1 = costs[0]+f(idx+1,days,costs,dp);

        // 7day
        int xx=find(idx,days,7);
        int op2=costs[1]+f(xx,days,costs,dp);

        // 30day
        xx=find(idx,days,30);
        int op3=costs[2]+f(xx,days,costs,dp);

        return dp[idx]= min({op1,op2,op3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return f(0,days,costs,dp);
    }
};