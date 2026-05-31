class Solution {
public:
    void f(vector<int>& candidates, int target,int i,vector<int>&list,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(list);
            return;
        }
        if(i==candidates.size()) return;

        //pick
        if(candidates[i]<=target){
            list.push_back(candidates[i]);
            f(candidates,target-candidates[i],i+1,list,ans);
            list.pop_back();
        }

        int j = i + 1;
        while (j < candidates.size() && candidates[j] == candidates[i])
            j++;

        f(candidates, target, j, list, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>list;
        vector<vector<int>>ans;
        f(candidates,target,0,list,ans);
        
        return ans;
    }
};