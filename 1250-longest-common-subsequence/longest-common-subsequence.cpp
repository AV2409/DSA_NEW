class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,string &text1, string &text2){

        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j]= 1+f(i-1,j-1,text1,text2);

        int op1=f(i-1,j,text1,text2);
        int op2=f(i,j-1,text1,text2);

        return dp[i][j]= max(op1,op2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        dp.assign(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2);
    }
};