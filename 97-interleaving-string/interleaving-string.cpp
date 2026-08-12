class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    bool f(int i,int j,string &s1, string &s2, string &s3){
        if(i==n && j==m) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        if(i<n && s1[i]==s3[i+j]) ans=ans||f(i+1,j,s1,s2,s3); 
        if(j<m && s2[j]==s3[i+j]) ans=ans||f(i,j+1,s1,s2,s3); 
        return dp[i][j]= ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        dp.assign(n+1,vector<int>(m+1,-1));
        if(s3.size()!=n+m) return false;

        return f(0,0,s1,s2,s3);
    }
};