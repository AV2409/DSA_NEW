class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for (int k = 0; k < n - 3; k++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            for (int i = k + 1; i < n - 2; i++) {
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;
                int l = i + 1, r = n - 1;
                while (l < r) {
                    long long sum = (long long)nums[k] + (long long)nums[i] + (long long)nums[l] + (long long)nums[r];
                    if (sum == target) {
                        ans.push_back({nums[k], nums[i], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++;
                        r--;
                    } else if (sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
