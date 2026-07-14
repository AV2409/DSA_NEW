class Solution {
public:
    unordered_set<string>dict;
    int n;
    vector<int>dp;
    bool solve(string &s,int idx){
        if(idx==n) return true;
        if(dp[idx]!=-1) return dp[idx];
        string x="";
        bool ans=false;
        for(int i=idx;i<n;i++){
            x+=s[i];
            if(dict.count(x)){
                ans=ans||solve(s,i+1);
            }
        }
        return dp[idx]= ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string x:wordDict) dict.insert(x);
        n=s.size();
        dp.assign(n,-1);
        return solve(s,0);
    }
};