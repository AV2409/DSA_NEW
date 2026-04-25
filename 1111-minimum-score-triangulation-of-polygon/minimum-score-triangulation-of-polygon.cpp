class Solution {
public:
    int f(int l,int r,vector<int>&values,vector<vector<int>>&dp){
        if(r-l==2) return values[l]*values[l+1]*values[r];
        if(l>r || r-l<2) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans=1e9;
        for(int i=l+1;i<r;i++){
            int x=f(i,r,values,dp);
            int y=f(l,i,values,dp);
            int tt=(values[l]*values[i]*values[r])+x+y;
            ans=min(ans,tt);
        }
        return dp[l][r]= ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int l=0;
        int r=values.size()-1;
        int n=values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(l,r,values,dp);
    }
};