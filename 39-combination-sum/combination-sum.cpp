class Solution {
public:
    void f(vector<int>& candidates, int target,int i,vector<int>&list,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(list);
            return;
        }
        if(i==candidates.size()) return;
        //not pick
        f(candidates,target,i+1,list,ans);

        //pick
        if(candidates[i]<=target){
            list.push_back(candidates[i]);
            f(candidates,target-candidates[i],i,list,ans);
            list.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>list;
        vector<vector<int>>ans;
        f(candidates,target,0,list,ans);
        return ans;
    }
};