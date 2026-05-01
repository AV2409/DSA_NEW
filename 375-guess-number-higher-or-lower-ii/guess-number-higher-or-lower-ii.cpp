class Solution {
public:
    vector<vector<int>>dp;
    int f(int st,int end){
        if(st>=end) return 0;
        if(end-st==1) return st;
        if(dp[st][end]!=-1) return dp[st][end];
        int ans=INT_MAX;
        int temp=0;
        for(int i=st;i<=end;i++){
            int x=f(st,i-1);
            int y=f(i+1,end);
            temp=i+max(x,y);
            ans=min(ans,temp);
        }
        return dp[st][end]= ans;

    }
    int getMoneyAmount(int n) {
        dp.assign(n+1,vector<int>(n+1,-1));
        return f(1,n);
    }
};