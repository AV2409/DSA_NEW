class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        int ans=0;
        for(int h=0;h<n;h++){
            if(nums[h]==0) k--;

            while(k<0){
                if(nums[l]==0) k++;
                l++;
            }

            ans=max(ans,h-l+1);
        }
        return ans;
    }
};