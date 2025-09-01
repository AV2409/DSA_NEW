class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int idx = 0; // last unique element position
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[idx]) { 
                idx++;
                nums[idx] = nums[i]; // place the new unique element
            }
        }

        return idx + 1; // length of unique portion
    }
};
