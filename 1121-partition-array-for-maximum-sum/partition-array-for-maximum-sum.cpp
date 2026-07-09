class Solution {
public:
    vector<int>dp;
    long long f(int i,vector<int>& arr, int k,int n){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans=0;
        int maxi=arr[i];
        int ss=min(i+k,n);
        for(int idx=i;idx<ss;idx++){
            int len=idx-i+1;
            maxi=max(arr[idx],maxi);
            int x1=len*maxi;
            long long x2=f(idx+1,arr,k,n);
            ans=max(ans,x1+x2);
        }
        return dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        dp.assign(n,-1);
        return f(0,arr,k,n);
    }
};