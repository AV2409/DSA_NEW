class Solution {
public:
    vector<int> list;
    vector<vector<int>> ans;
    void helper(int i,vector<int>& nums){
        if(i<0){
            ans.push_back(list);
            return;
        }
        
        //pick
        list.push_back(nums[i]);
        helper(i-1,nums);
        list.pop_back();

        //notpick
        int j=i-1;
        while(j>=0 && nums[j]==nums[i]) j--;
        helper(j,nums);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        helper(n-1,nums);
        return ans;
    }
};