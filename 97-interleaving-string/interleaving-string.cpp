class Solution {
public:
    int n1;
    int n2;
    int n3;
    vector<vector<int>>dp;
    bool f(int i,int j,string &s1, string &s2, string &s3){
        int k=i+j;
        if(i==n1 && j==n2) return true;
        if(i==n1){
            return s2.substr(j,n2-j)==s3.substr(k,n3-k);
        }
        if(j==n2){
            return s1.substr(i,n1-i)==s3.substr(k,n3-k);
        }

        if(dp[i][j]!=-1) return dp[i][j];

        bool op1=false;
        bool op2=false;


        if(s1[i]==s3[k]) op1=f(i+1,j,s1,s2,s3);
        if(s2[j]==s3[k]) op2=f(i,j+1,s1,s2,s3);

        return dp[i][j] = op1||op2;
        

    }
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.size();
        n2=s2.size();
        n3=s3.size();
        if(n1+n2!=n3) return false;
        dp.assign(n1,vector<int>(n2,-1));
        return f(0,0,s1,s2,s3);
    }
};