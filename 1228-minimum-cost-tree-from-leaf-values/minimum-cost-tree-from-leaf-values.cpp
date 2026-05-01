class Solution {
public:
    //{ans,max}
    vector<vector<int>>maxi;
    vector<vector<int>>dp;
    int f(int st,int end,vector<int>& arr){
        if(st==end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        int ans=INT_MAX;
        for(int i=st;i<end;i++){
            int x=f(st,i,arr);
            int y=f(i+1,end,arr);

            int cost=x+y+maxi[st][i]*maxi[i+1][end];
            ans=min(ans,cost);
        }
        return dp[st][end]= ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        maxi.assign(n,vector<int>(n,-1));
        dp.assign(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            int tt=arr[i];
            for(int j=i;j<n;j++){
                tt=max(tt,arr[j]);
                maxi[i][j]=tt;
            }
        }
        return f(0,n-1,arr);
    }
};