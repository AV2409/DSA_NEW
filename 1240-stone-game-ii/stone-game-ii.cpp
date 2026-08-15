class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int f(int i, int M, vector<int>& piles) {
        if (i >= n) {
            return 0;
        }
        if(dp[i][M]!=-1) return dp[i][M];
        int ans=INT_MIN;
        int sum=0;
        for(int idx=i;idx<min(n,i+(2*M));idx++){
            sum+=piles[idx];
            int x=sum-f(idx+1,max(M,idx-i+1),piles);
            ans=max(ans,x);
        }
        return dp[i][M]= ans;
    }

    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        dp.assign(n,vector<int>(2*n+1,-1));
        int sum=accumulate(piles.begin(),piles.end(),0);
        int diff=f(0,1,piles);
        return (diff+sum)/2;
    }
};