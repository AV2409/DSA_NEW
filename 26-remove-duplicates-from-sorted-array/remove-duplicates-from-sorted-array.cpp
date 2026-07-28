class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;
        int n=nums.size();
        int i=1;

        while(i<n){
            while(i<n && nums[i]==nums[idx]) i++;
            if(i<n){
                idx++;
                nums[idx]=nums[i];
                i++;
            }
        }
        return idx+1;
    }
};