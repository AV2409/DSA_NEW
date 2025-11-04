class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        map<int,int>mp;
        int res1 = 0;
        while (r < n) {
            if (k <= 0)
                break;
            mp[nums[r]]++;
            while (mp.size() > k) {
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            res1 += r - l + 1;
            r++;
        }

        l = 0;
        r = 0;
        k = k - 1;
        map<int,int>mp1;
        int res2 = 0;
        while (r < n) {
            if (k <= 0)
                break;
            mp1[nums[r]]++;
            while (mp1.size() > k) {
                mp1[nums[l]]--;
                if(mp1[nums[l]]==0) mp1.erase(nums[l]);
                l++;
            }
            res2 += r - l + 1;
            r++;
        }
        return res1 - res2;
    }
};