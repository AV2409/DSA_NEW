class Solution {
public:
    int n;
    vector<int> list;
    vector<vector<int>> ans;
    void solve(int i,vector<int>&nums) {
        if(i==n){
            ans.push_back(list);
            return;
        }

        list.push_back(nums[i]);
        solve(i+1,nums);
        list.pop_back();

        solve(i+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        solve(0,nums);
        return ans;
    }
};