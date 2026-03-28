class Solution {
public:

    void f(vector<int>& nums,vector<vector<int>>&ans,int i){
        if(i==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            f(nums,ans,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        f(nums,ans,0);
        return ans;
    }
};