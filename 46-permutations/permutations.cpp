class Solution {
public:

    void f(vector<int>& nums,vector<int>&temp,vector<vector<int>>&ans,unordered_map<int,int>mp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1){
                temp.push_back(nums[i]);
                mp[nums[i]]=2;
                f(nums,temp,ans,mp);
                mp[nums[i]]=1;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        vector<vector<int>>ans;
        vector<int>temp;
        f(nums,temp,ans,mp);
        return ans;
    }
};