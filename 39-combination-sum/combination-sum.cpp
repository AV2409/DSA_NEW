class Solution {
public:

    void f(vector<int>& candidates, int target,vector<int>&temp,vector<vector<int>>&ans,int i,int sum){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(i==candidates.size()) return;
        if(sum>target) return;

        //not take it
        f(candidates,target,temp,ans,i+1,sum);

        //take it
        temp.push_back(candidates[i]);
        sum=sum+candidates[i];
        f(candidates,target,temp,ans,i,sum);
        temp.pop_back();
        sum-=candidates[i];
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(candidates,target,temp,ans,0,0);
        return ans;
    }
};