class Solution {
public:
    int f(int i, int n, int k, vector<int>& arr,vector<int>& dp) {
        if(i==n) return 0;

        if(dp[i]!=-1) return dp[i];
        if (n - i <= k) {
            int maxe = arr[i];
            for (int t = i; t < n; t++) {
                maxe = max(maxe, arr[t]);
            }
            return dp[i]= (n - i) * maxe;
        }

        int ans=0;
        int maxe = arr[i];
        for(int t=i;t<i+k;t++){
            maxe=max(maxe,arr[t]);
            int temp=maxe*(t-i+1)+f(t+1,n,k,arr,dp);
            ans=max(ans,temp);
        }
        return dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return f(0, n, k, arr,dp);
    }
};