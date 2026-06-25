class Solution {
public:
    bool isPossible(int mid,vector<int>& nums, int k) {
        int cnt = 1;
        long long sum = 0;
        for (int x : nums) {
            if (sum + x <= mid) {
                sum += x;
            } else {
                cnt++;
                sum = x;
            }

            if (cnt > k)
                return false;
        }

        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        long long h = accumulate(nums.begin(), nums.end(), 0LL);

        int ans = h;

        while (l <= h) {
            long long mid = l + (h - l) / 2;

            if (isPossible(mid, nums, k)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};