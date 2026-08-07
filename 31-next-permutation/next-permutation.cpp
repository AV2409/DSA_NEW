class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        int pivot=i;
        if(pivot==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int toswapidx=-1;
        for(int i=n-1;i>pivot;i--){
            if(nums[pivot]<nums[i]) {
                toswapidx=i;
                break;
            }
        }
        
        swap(nums[pivot],nums[toswapidx]);
        reverse(nums.begin()+pivot+1,nums.end());
    }
};