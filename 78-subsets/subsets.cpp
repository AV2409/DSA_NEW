class Solution {
public:
    int n;
    vector<int> list;
    vector<vector<int>> ans;
    void helper(int i,vector<int>& nums){
        if(i<0){
            ans.push_back(list);
            return;
        }
        //notpick
        helper(i-1,nums);
        //pick
        list.push_back(nums[i]);
        helper(i-1,nums);
        list.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        helper(n-1,nums);
        return ans;
    }
};