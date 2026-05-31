class Solution {
public:
    void f(vector<int>& nums,int i,vector<int>& list,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(list);
            return;
        }

        list.push_back(nums[i]);
        f(nums,i+1,list,ans);
        list.pop_back();

        int j=i+1;
        while(j<nums.size() && nums[i]==nums[j]) j++;
        f(nums,j,list,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>list;
        f(nums,0,list,ans);
        return ans;
    }
};