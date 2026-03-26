class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1e9;
        for (int i = 0; i < n - 2; i++) {

            // if (i > 0 && nums[i] == nums[i - 1])
            //     continue;
            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }

                if (sum == target)
                    return sum;

                else if (sum < target) l++;

                else r--;
            }
        }
        return ans;
    }
};