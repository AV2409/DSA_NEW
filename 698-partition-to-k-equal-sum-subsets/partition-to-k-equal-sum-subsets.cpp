class Solution {
public:
    vector<int>vis;
    int groups=0;
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
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k)
            return false;
        
        n=nums.size();
        vis.assign(n,0);
        reqSum=sum/k;
        return solve(0,nums,reqSum,k);
        
    }
};