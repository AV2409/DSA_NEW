class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        
        int sum=nums[0];
        for (int i = 1; i < n; i++) {
            sum+=nums[i];
            prefix[i] = nums[i - 1] + prefix[i - 1];
            
        }

        for(int i=0;i<n;i++){
            if(prefix[i]==(sum-prefix[i]-nums[i])) return i;
        }
        return -1;
    }
};