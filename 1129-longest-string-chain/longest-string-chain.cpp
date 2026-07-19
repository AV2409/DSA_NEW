class Solution {
public:
    int lcs(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }

    bool check(string &s1,string &s2){
        int n1=s1.size();
        int n2=s2.size();
        if(n1+1!=n2) return false;

        int x=lcs(s1,s2);
        return x==n1;
        
    }
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),comp);
        vector<int>dp(n,1);
        int lis=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[j],words[i])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            lis=max(lis,dp[i]);
        }
        return lis;
    }
};