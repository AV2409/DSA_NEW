class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zidx = 0;

        while (zidx < n) {
            while (zidx<n && nums[zidx] != 0)
                zidx++;
            int nzidx = zidx;
            while (nzidx<n && nums[nzidx] == 0)
                nzidx++;
            if (zidx < n && nzidx < n)
                swap(nums[zidx], nums[nzidx]);
            zidx++;
        }
    }
};