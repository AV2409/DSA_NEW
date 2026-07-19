class Solution {
public:
    int n1;
    int n2;
    vector<vector<int>>dp;
    bool f(int i,int j,string &s, string &p){
        if(i>=n1) {
            while(j<n2 && p[j]=='*') j++;
            if(j==n2) return true;
            return false;
        }
        if(j>=n2) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[j]=='*'){
            //0 char 
            bool op1=f(i,j+1,s,p);
            //1 or more
            bool op2=f(i+1,j,s,p);

            return dp[i][j]= op1||op2;
        }
        else if(p[j]=='?'){
            return dp[i][j]= f(i+1,j+1,s,p);
        }
        else{
            if(s[i]==p[j]) return dp[i][j]= f(i+1,j+1,s,p);
            return dp[i][j]= false;
        }
    }
    bool isMatch(string s, string p) {
        n1 = s.size();
        n2 = p.size();
        dp.assign(n1,vector<int>(n2,-1));
        return f(0, 0, s, p);
    }
};