class Solution {

public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;

        int check[100000]={0};
        int index;

        for(int i=0;i<nums.size();i++){
            index=nums[i]-1;
            check[index]++;
            if(check[index]>1) ans.push_back(nums[i]);

        }

        return ans;

        
    }
};
