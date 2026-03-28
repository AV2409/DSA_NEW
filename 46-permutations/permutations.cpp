class Solution {
public:

    void f(vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans,vector<bool>&vis){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]==0){
                temp.push_back(nums[i]);
                vis[i]=1;
                f(nums,temp,ans,vis);
                vis[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool>vis(n);
        vector<vector<int>>ans;
        vector<int>temp;
        f(nums,temp,ans,vis);
        return ans;
    }
};