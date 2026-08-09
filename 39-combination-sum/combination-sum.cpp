class Solution {
public:
    vector<int> list;
    vector<vector<int>> ans;
    void helper(int i, vector<int>& nums, int target) {
        if (i < 0) {
            if (target == 0)
                ans.push_back(list);
            return;
        }
        if (target == 0){
            ans.push_back(list);
            return;
        }
            
        // notpick
        helper(i - 1, nums, target);
        // pick
        if (target >= nums[i]) {
            list.push_back(nums[i]);
            helper(i, nums,target-nums[i]);
            list.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        helper(n-1,candidates,target);
        return ans;
    }
};