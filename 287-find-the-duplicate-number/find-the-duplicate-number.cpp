class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            int corrected=abs(nums[i])-1;
            if(nums[corrected]<0) return corrected+1;
            nums[corrected]=-nums[corrected];
        }
        return 0;
    }
};