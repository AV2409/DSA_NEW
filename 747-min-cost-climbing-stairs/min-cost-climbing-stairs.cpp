class Solution {
public:
    int n;
    vector<int>dp;
    int f(int i,vector<int>& cost){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int op1=f(i+1,cost);
        int op2=f(i+2,cost);

        return dp[i]= cost[i]+min(op1,op2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        dp.assign(n,-1);
        return min(f(0,cost),f(1,cost));
    }
};