class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int ele=nums[i];
            if(ele<=0 || ele>=n) {
                i++;
                continue;
            }
            int idx=ele-1;
            if(i!=idx && nums[i]!=nums[idx]){
                swap(nums[i],nums[idx]);
            }
            else i++;
        }

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};