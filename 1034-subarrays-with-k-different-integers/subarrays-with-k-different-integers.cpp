class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if(k==0) return 0;
        int n=nums.size();
        unordered_map<int,int>mp;

        int ans=0;
        int l=0;
        int unq=0;
        for(int r=0;r<n;r++){
            if(mp[nums[r]]==0) unq++;
            mp[nums[r]]++;
            while(unq>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) unq--;
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};