class Solution {
public:
    set<string>dict;
    vector<int> dp;
    bool solve(string &s,int idx){
        if(idx==s.size()) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.size();i++){
            string first=s.substr(idx,i-idx+1);
            if(dict.count(first)){
                if(solve(s,i+1)) return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size(),-1);
        for(string x:wordDict) dict.insert(x);
        return solve(s,0);
    }
};