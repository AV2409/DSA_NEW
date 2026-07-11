class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,string &s, string &t){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int op1=0;
        int op2=0;
        if(s[i]==t[j]) op1=f(i-1,j-1,s,t);
        op2=f(i-1,j,s,t);
        return dp[i][j]= op1+op2;
    }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        dp.assign(m,vector<int>(n,-1));
        return f(m-1,n-1,s,t);
    }
};