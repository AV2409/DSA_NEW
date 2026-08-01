class Solution {
public:
    set<string>st;
    int n;
    vector<int>dp;
    bool f(int i,string &s){
        if(i>=n) return true;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        bool ans=false;
        for(int part=i;part<n;part++){
            temp+=s[part];
            if(st.count(temp)){
                ans=ans||f(part+1,s);
            }
        }
        return dp[i]= ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        st.insert(wordDict.begin(),wordDict.end());
        dp.assign(n,-1);
        return f(0,s);
    }
};