class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,string &text1, string &text2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j]= 1+f(i-1,j-1,text1,text2);
        }

        return dp[i][j]= max(f(i-1,j,text1,text2),f(i,j-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        dp.assign(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,text1,text2);
    }
};