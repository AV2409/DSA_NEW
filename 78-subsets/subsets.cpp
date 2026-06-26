class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<int>& list,vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(list);
            return;
        }

        solve(idx+1,nums,list,ans);

        list.push_back(nums[idx]);
        solve(idx+1,nums,list,ans);
        list.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> list;
        vector<vector<int>> ans;
        solve(0,nums,list,ans);
        return ans;

    }
};