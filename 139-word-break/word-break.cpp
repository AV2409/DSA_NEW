class Solution {
public:
    int n;
    set<string>st;
    vector<int>dp;
    bool f(int idx,string &s){
        if(idx==n) return true;
        if(dp[idx]!=-1) return dp[idx];
        bool ans=false;
        string x="";
        for(int i=idx;i<n;i++){
            x+=s[i];
            if(st.count(x)) ans=ans||f(i+1,s);
            if(ans) return dp[idx]= true;
        }
        return dp[idx]= ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        dp.assign(n,-1);
        for(string &w:wordDict){
            st.insert(w);
        }

        return f(0,s);
    }
};