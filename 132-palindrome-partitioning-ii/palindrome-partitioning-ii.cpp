class Solution {
public:
    bool isPal(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,string &str,int n,vector<int>&dp){
        if(i==n) return 0;
        int mini=2000;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<n;j++){
            if(isPal(i,j,str)){
                int cc=1+f(j+1,str,n,dp);
                mini=min(cc,mini);
            }
        }
        return dp[i]= mini;

    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return f(0,s,n,dp)-1;
    }
};