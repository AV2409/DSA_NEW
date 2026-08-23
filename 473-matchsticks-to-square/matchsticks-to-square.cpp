class Solution {
public:
    vector<int>vis;
    int reqSum;
    int n;
    bool solve(int st,vector<int>& nums,int sum,int rem){
        if(rem==1) return true;
        if(sum==0) {
            return solve(0,nums,reqSum,rem-1);
        }
        
        for(int i=st;i<n;i++){
            if(vis[i]) continue;
            if(nums[i]>sum) continue;

            vis[i]=1;
            if(solve(i+1,nums,sum-nums[i],rem)) return true;
            vis[i]=0;
        }
        return false;

    }
    bool makesquare(vector<int>& matchsticks) {
        int k=4;
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4)
            return false;
        
        n=matchsticks.size();
        vis.assign(n,0);
        reqSum=sum/4;
        return solve(0,matchsticks,reqSum,4);
    }
};