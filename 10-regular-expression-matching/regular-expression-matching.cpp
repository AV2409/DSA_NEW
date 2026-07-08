class Solution {
public:
    int n;
    int m;
    vector<vector<int>>dp;
    bool f(int i,int j,string &s, string &p){
        if(i>=n && j>=m) return true;

        if(i>=n){
            while(j+1<m && p[j+1]=='*') j+=2;
            if(j>=m) return true;
            return false;
        } 

        if(j>=m) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        char ch='#';
        if(j+1<m) ch=p[j+1];
        if(ch=='*'){
            //0 match chars of p in s
            bool op1=f(i,j+2,s,p);
            //1 or more
            bool op2=false;
            if(s[i]==p[j]) op2=f(i+1,j,s,p);
            else if(p[j]=='.') op2=f(i+1,j,s,p);
            return dp[i][j]= op1||op2;
        }
        else if(p[j]=='.'){
            return dp[i][j]= f(i+1,j+1,s,p);
        }
        else{
            if(s[i]==p[j]) return dp[i][j]= f(i+1,j+1,s,p);
            return dp[i][j]= false;
        }
    }
    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        dp.assign(n,vector<int>(m,-1));
        return f(0,0,s,p);
    }
};