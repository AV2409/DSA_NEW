class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;

        bool canBe = true;

        for (int i = 1; i < n; i++) {
            if (nums[idx] != nums[i]) {
                nums[++idx] = nums[i];
                canBe=true;
            } else {
                if (canBe) {
                    nums[++idx] = nums[i];
                    canBe=false;
                }
            }
        }
        return idx+1;
    }
};