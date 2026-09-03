class Solution {
public:
    vector<int>dp;
    int f(int i,string &s){
        if(i<0) return 1;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0'){
            if(i-1>=0 && (s[i-1]=='1'||s[i-1]=='2')) return dp[i] = f(i-2,s);
            return dp[i]= 0;
        }

        if(s[i]>='1' && s[i]<='6'){
            int op1=f(i-1,s);
            int op2=0;
            if(i-1>=0 && (s[i-1]=='1'||s[i-1]=='2')) op2=f(i-2,s);
            return dp[i]= op1+op2;
        }

        if(s[i]>='7' && s[i]<='9'){
            int op1=f(i-1,s);
            int op2=0;
            if(i-1>=0 && s[i-1]=='1') op2=f(i-2,s);
            return dp[i]= op1+op2;
        }
        return dp[i]= 0;

    }
    int numDecodings(string s) {
        int n=s.size();
        dp.assign(n,-1);
        return f(n-1,s);
    }
};