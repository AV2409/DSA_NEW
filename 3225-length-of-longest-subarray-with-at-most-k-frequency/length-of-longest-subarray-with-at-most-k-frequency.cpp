class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt=0;

        int l=0;
        int n=nums.size();
        int ans=1;
        for(int r=0;r<n;r++){
            mp[nums[r]]++;
            if(mp[nums[r]]==k+1) cnt++;
            while(cnt>0){
                mp[nums[l]]--;
                if(mp[nums[l]]==k) cnt--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};