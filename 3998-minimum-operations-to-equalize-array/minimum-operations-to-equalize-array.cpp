class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool flag = false;
        int n=nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] != nums[i])
                flag = true;
        }

        if (flag)
            return 1;
        
        return 0;
    }
};