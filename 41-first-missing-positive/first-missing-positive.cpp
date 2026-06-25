class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<bool>hash(1e5+1,false);

        for(int i=0;i<n;i++){
            if(nums[i]>0 && nums[i]<=1e5) hash[nums[i]]=true;
        }
        for(int i=1;i<=1e5;i++){
            if(!hash[i]) return i;
        }
        return 1e5+1;
    }
};