class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        int n=nums.size();
        for(int i=0;i<n;i++){
            auto lb=lower_bound(lis.begin(),lis.end(),nums[i]);
            if(lb==lis.end()) lis.push_back(nums[i]);
            else{
                int idx=lb-lis.begin();
                lis[idx]=nums[i];
            }
        }
        return lis.size();
    }
};