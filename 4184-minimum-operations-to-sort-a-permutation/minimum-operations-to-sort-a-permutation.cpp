class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int idx = -1;
        bool flag = false;

        for (int i = 0; i < n - 1; i++) {
            int d = abs(nums[i] - nums[i + 1]);

            if (!(d == 1 || d == n - 1))
                return -1;

            if (nums[i] == 0) {
                idx = i;
                if (nums[i + 1] != 1)
                    flag = true;
            }
        }

        if (nums[n - 1] == 0) {
            idx = n - 1;
            if (nums[0] != 1)
                flag = true;
        }

        int d = abs(nums[n - 1] - nums[0]);
        if (!(d == 1 || d == n - 1))
            return -1;

        if (!flag) {
            return min(idx, n-idx+2);
        }

        int reverseThenRotate = 1 + (n - 1 - idx);
        int rotateThenReverse = 1 + ((idx + 1) % n);

        return min(reverseThenRotate, rotateThenReverse);
    }
};