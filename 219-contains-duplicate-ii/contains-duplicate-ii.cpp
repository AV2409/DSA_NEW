class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int i = 0;
        while (i < k && i<n) {
            mp[nums[i]]++;
            if (mp[nums[i]] > 1)
                return true;
            i++;
        }
        
        int idx = 0;
        while (i < n) {
            mp[nums[i]]++;
            if (mp[nums[i]] > 1)
                return true;
            i++;
            mp[nums[idx]]--;
            idx++;
            
        }
        return false;
    }
};