class Solution {
public:
    void solve(int i,int n,vector<int>& nums,vector<int>& s,vector<vector<int>>&ans){
        if(i==n){
            ans.push_back(s);
            return;
        }

        //not pick
        solve(i+1,n,nums,s,ans);

        //pick
        s.push_back(nums[i]);
        solve(i+1,n,nums,s,ans);
        s.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>s;
        vector<vector<int>>ans;
        solve(0,n,nums,s,ans);
        return ans;
    }
};