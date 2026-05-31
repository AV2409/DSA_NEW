class Solution {
public:
    void f(vector<int>& nums,int n,int i,vector<int>& list,vector<vector<int>>&ans){
        if(i==n){
            ans.push_back(list);
            return;
        }

        list.push_back(nums[i]);
        f(nums,n,i+1,list,ans);
        list.pop_back();

        int j=i+1;
        while(j<n && nums[i]==nums[j]) j++;
        f(nums,n,j,list,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>list;
        int n=nums.size();
        f(nums,n,0,list,ans);
        return ans;
    }
};