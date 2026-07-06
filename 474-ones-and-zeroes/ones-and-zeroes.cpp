class Solution {
public:
    vector<pair<int,int>> cnt;
    vector<vector<vector<int>>>dp;
    int f(int i,vector<string>& strs, int m, int n){
        if(i<0) {
            return 0;
        }
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int np=f(i-1,strs,m,n);
        int p=0;
        string word=strs[i];
        int zeros=cnt[i].first;
        int ones=cnt[i].second;

        if(zeros<=m && ones<=n) p=1+f(i-1,strs,m-zeros,n-ones);
        return dp[i][m][n]= max(p,np);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        for(string s:strs){
            int o=0;
            int z=0;
            for(char c:s){
                if(c=='0') z++;
                if(c=='1') o++;
            }
            cnt.push_back({z,o});
        }
        int x=strs.size();
        dp.assign(x,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return f(x-1,strs,m,n);
    }
};