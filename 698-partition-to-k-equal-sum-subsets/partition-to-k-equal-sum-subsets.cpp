class Solution {
public:
    vector<int>vis;
    int groups=0;
    int reqSum;
    int n;
    bool solve(int i,vector<int>& nums,int sum,int rem){
        if(rem==0) return true;
        if(sum==0) {
            return solve(0,nums,reqSum,rem-1);
        }
        if(i>=n) return false;
        if(vis[i]) return solve(i+1,nums,sum,rem);

        //not pick
        bool np=solve(i+1,nums,sum,rem);

        //
        bool p=false;
        if(nums[i]<=sum) {
            vis[i]=1;
            p=solve(i+1,nums,sum-nums[i],rem);
            vis[i]=0;
        }
        return p||np;

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