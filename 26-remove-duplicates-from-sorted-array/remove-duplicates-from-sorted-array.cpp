class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        int j = 1;
        int i=0;
        while(i<n) {
            int j = i + 1;
            while (j < n && nums[j] == nums[j - 1])
                j++;
            if (j < n)
                nums[idx+1]=nums[j];
            idx++;
            i=j;
        }

        return idx;
    }
};