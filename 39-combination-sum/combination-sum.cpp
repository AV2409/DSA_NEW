class Solution {
public:
    vector<vector<int>>ans;
    vector<int>list;
    int n;
    void f(int i,vector<int>& candidates, int target){
        if(i==n){
            if(target==0){
                ans.push_back(list);
            }
            return;
        }
        if(target==0){
            ans.push_back(list);
            return;
        }

        //pick
        if(target-candidates[i]>=0){
            list.push_back(candidates[i]);
            f(i,candidates,target-candidates[i]);
            list.pop_back();
        }

        f(i+1,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        f(0,candidates,target);
        return ans;
    }
};