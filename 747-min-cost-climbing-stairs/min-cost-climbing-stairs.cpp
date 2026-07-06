class Solution {
public:
    vector<int>dp;
    int f(int i,vector<int>& cost){
       if(i==0) return cost[0]; 
       if(i==1) return cost[1];
        if(dp[i]!=-1) return dp[i];
       int op1=INT_MAX;
       int op2=INT_MAX;

       if(i-1>=0) op1=cost[i]+f(i-1,cost);
       if(i-2>=0) op2=cost[i]+f(i-2,cost);

       return dp[i]= min(op1,op2); 

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.assign(n+1,-1);
        return min(f(n-2,cost),f(n-1,cost));
    }
};