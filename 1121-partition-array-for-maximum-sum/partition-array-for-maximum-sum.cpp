class Solution {
public:
    int n;
    vector<long long>dp;
    long long f(int i,vector<int>& arr, int k){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans=0;
        int maxi=-1;
        for(int idx=i;idx<min(i+k,n);idx++){
            maxi=max(maxi,arr[idx]);
            int len=idx-i+1;
            long long val=1LL*len*maxi;
            ans=max(ans,val+f(idx+1,arr,k));
        }
        return dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        dp.assign(n,-1);
        return f(0,arr,k);
    }
};