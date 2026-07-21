class Solution {
public:
    vector<vector<int>>dp;
    int f(int st,int end,vector<int>& arr){
        if(st>=end-1) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        int ans=INT_MAX;
        int len=arr[end]-arr[st];
        for(int i=st+1;i<end;i++){
            int temp=len+f(st,i,arr)+f(i,end,arr);
            ans=min(ans,temp);
        }
        return dp[st][end]= ans;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<int>arr;
        arr.push_back(0);
        sort(cuts.begin(),cuts.end());
        for(int x:cuts) arr.push_back(x);
        arr.push_back(n);
        int ss=arr.size();
        dp.assign(ss,vector<int>(ss,-1));
        return f(0,ss-1,arr);

    }
};