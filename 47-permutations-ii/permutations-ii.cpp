class Solution {
public:
    vector<int>vis;
    void f(vector<int>& nums,vector<int>&list,vector<vector<int>>&ans){
        if(list.size()==nums.size()){
            ans.push_back(list);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(!vis[j]){
                if(j>0 && nums[j]==nums[j-1] && !vis[j-1]) continue;
                list.push_back(nums[j]);
                vis[j]=1;
                f(nums,list,ans);
                list.pop_back();
                vis[j]=0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vis.assign(n,0);
        vector<vector<int>>ans;
        vector<int>list;
        f(nums,list,ans);
        return ans;
    }
};