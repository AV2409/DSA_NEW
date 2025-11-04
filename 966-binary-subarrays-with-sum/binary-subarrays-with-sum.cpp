class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l=0;
        int r=0;
        int n=nums.size();
        int sum=0;
        int cnt1=0;
        while(r<n){
            if(goal<0) break;
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt1+=r-l+1;
            r++;
        }

        l=0;
        r=0;
        sum=0;
        goal=goal-1;
        int cnt2=0;
        while(r<n){
            if(goal<0) break;
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cnt2+=r-l+1;
            r++;
        }
        return cnt1-cnt2;
    }
};