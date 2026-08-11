class Solution {
public:
    int n;
    vector<int>dp;
    int f(int i,string &s){
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        char ch=s[i];
        int ans=0;
        if(ch=='1'){
            ans+=f(i+1,s);
            if(i+2<=n) ans+=f(i+2,s);
        }
        else if(ch=='2'){
            ans+=f(i+1,s);
            if(i+2<=n && s[i+1]>='0' && s[i+1]<='6') ans+=f(i+2,s);
        }
        else{
            ans+=f(i+1,s);
        }
        return dp[i]= ans;
    }
    int numDecodings(string s) {
        n=s.size();
        dp.assign(n,-1);
        return f(0,s);
    }
};