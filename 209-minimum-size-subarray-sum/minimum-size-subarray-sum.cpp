class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int ans = 1e9;
        int sum = 0;

        for(int r=0;r<n;r++){
            // include r
            sum+=nums[r];

            while(sum>=target){
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        if (ans == 1e9)
            return 0;
        return ans;
    }
};