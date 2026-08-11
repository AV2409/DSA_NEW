class Solution {
public:
    vector<int>dp;
    int f(int i,vector<int>& cost){
        if(i==0 || i==1) return 0;
        if(dp[i]!=-1) return dp[i];
        int op1=1e9;
        int op2=1e9;

        if(i-1>=0){
            op1=f(i-1,cost)+cost[i-1];
        }
        if(i-2>=0){
            op2=f(i-2,cost)+cost[i-2];
        }
        return dp[i]= min(op1,op2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.assign(n+1,-1);
        return f(n,cost);
    }
};