class Solution {
public:
int f(int i,int j,vector<int>& cuts,vector<vector<int>>&dp){
    if (j - i <= 1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int temp=1e9;
    for(int k=i+1;k<j;k++){
        int cost=f(i,k,cuts,dp)+f(k,j,cuts,dp)+(cuts[j]-cuts[i]);
        temp=min(cost,temp);
    }
    return dp[i][j]=temp;
}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return f(0, m - 1, cuts,dp);
    }
};