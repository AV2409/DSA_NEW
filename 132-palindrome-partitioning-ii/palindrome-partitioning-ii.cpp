class Solution {
public:
    vector<int>dp;
    bool isPal(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i,string &s){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int idx=i;idx<s.size();idx++){
            if(isPal(i,idx,s)){
                ans=min(ans,1+f(idx+1,s));
            }
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n=s.size();
        dp.assign(n,-1);
        return f(0,s)-1;
    }
};