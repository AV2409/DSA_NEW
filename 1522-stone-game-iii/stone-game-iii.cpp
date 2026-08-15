class Solution {
public:
    int n;
    vector<int>dp;
    int f(int i, vector<int>& piles) {
        if (i >= n) {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        int sum=0;
        for(int idx=i;idx<min(n,i+3);idx++){
            sum+=piles[idx];
            int x=sum-f(idx+1,piles);
            ans=max(ans,x);
        }
        return dp[i]= ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.assign(n,-1);
        int diff=f(0,stoneValue);
        if(diff>0) return "Alice";
        else if(diff<0) return "Bob";
        else return "Tie";
    }
};