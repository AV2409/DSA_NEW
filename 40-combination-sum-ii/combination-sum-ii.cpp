class Solution {
public:
    int n;
    vector<int> list;
    vector<vector<int>> ans;
    void helper(int i, vector<int>& nums, int target) {
        if (i == n) {
            if (target == 0)
                ans.push_back(list);
            return;
        }
        if (target == 0){
            ans.push_back(list);
            return;
        }
            
        
        // pick
        if (target >= nums[i]) {
            list.push_back(nums[i]);
            helper(i+1, nums,target-nums[i]);
            list.pop_back();
        }
        // notpick
        int j=i+1;
        while(j<n && nums[j]==nums[i]) j++;
        helper(j, nums, target);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        n=candidates.size();
        helper(0,candidates,target);
        return ans;
    }
};