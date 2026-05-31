class Solution {
public:
    void f(int k, int n,vector<int>&nums,int i,vector<int>&list,vector<vector<int>>&ans){
        if(k==0 && n==0){
            ans.push_back(list);
            return;
        }
        if(k==0||n==0||i==9) return;
        
        f(k,n,nums,i+1,list,ans);

        list.push_back(nums[i]);
        f(k-1,n-nums[i],nums,i+1,list,ans);
        list.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums(9);
        for(int i=1;i<=9;i++) nums[i-1]=i;
        vector<int>list;
        vector<vector<int>>ans;
        f(k,n,nums,0,list,ans);
        return ans;
    }
};