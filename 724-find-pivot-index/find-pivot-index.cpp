class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int left=0;
        
        int sum=nums[0];
        for (int i = 1; i < n; i++) {
            sum+=nums[i];
        }
        int right=sum-nums[0];
        if(left==right) return 0;
        for (int i = 1; i < n; i++) {
            left+=nums[i-1];
            right=sum-left-nums[i];
            if(left==right) return i;    
        }

        return -1;
    }
};