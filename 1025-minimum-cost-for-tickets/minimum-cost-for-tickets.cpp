class Solution {
public:
    vector<int>dp;
    int f(int i,int timer,vector<int>& days, vector<int>& costs){
        if(i==days.size()) return 0;
        
        if(timer>days[i]) return f(i+1,timer,days,costs);
        if(dp[i]!=-1) return dp[i];
        int one=costs[0]+f(i+1,days[i]+1,days,costs);

        int seven=costs[1]+f(i+1,days[i]+7,days,costs);

        int thirty=costs[2]+f(i+1,days[i]+30,days,costs);

        return dp[i]= min({one,seven,thirty});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        dp.assign(n,-1);
        return f(0,0,days,costs);
    }
};