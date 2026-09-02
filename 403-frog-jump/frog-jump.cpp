class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool f(int i,vector<int>& stones,int prevJump){
        if(i==n-1) return true;
        if(dp[i][prevJump]!=-1) return dp[i][prevJump];
        bool ans=false;
        
        int j1=prevJump-1;
        int j2=prevJump;
        int j3=prevJump+1;
        vector<int>jumps={j1,j2,j3};
        int idx=i+1;
        for(int j:jumps){
            if(j<=0) continue;
            int newLoc=stones[i]+j;
            while(idx<n && stones[idx]<newLoc) idx++;
            if(idx<n && stones[idx]==newLoc) {
                ans=ans||f(idx,stones,j);
            }
        }
        return dp[i][prevJump]= ans;


    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        if(n==2){
            return stones[1]==1;
        }
        if(stones[1]!=1) return false;
        dp.assign(n, vector<int>(n + 1, -1));
        return f(1,stones,1);
    }
};