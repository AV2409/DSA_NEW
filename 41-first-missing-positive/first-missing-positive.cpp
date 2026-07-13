class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]==i+1) {
                i++;
                continue;
            }
            if(nums[i]<0){
                i++;
                continue;
            }
            int correctidx=nums[i]-1;
            if(correctidx >= 0 && correctidx<n && nums[i] != nums[correctidx]) {
                swap(nums[i],nums[correctidx]);
            }
            else i++;

        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};