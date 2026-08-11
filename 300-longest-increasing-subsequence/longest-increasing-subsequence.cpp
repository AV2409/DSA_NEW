class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis;

        for(int i=0;i<n;i++){
            int ele=nums[i];
            auto lb=lower_bound(lis.begin(),lis.end(),ele);
            if(lb==lis.end()) lis.push_back(ele);
            else {
                int idx=lb-lis.begin();
                lis[idx]=ele;
            }
        }
        return lis.size();
    }
};