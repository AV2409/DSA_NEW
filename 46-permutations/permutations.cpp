class Solution {
public:
    vector<int>vis;
    int n;
    void f(vector<int>& nums,vector<int>&list,vector<vector<int>>&ans){
        if(list.size()==n){
            ans.push_back(list);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(!vis[j]){
                list.push_back(nums[j]);
                vis[j]=1;
                f(nums,list,ans);
                list.pop_back();
                vis[j]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vis.assign(n,0);
        vector<vector<int>>ans;
        vector<int>list;
        f(nums,list,ans);
        return ans;
    }
};