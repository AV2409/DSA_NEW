class Solution {
public:
    int n;
    vector<int>list;
    vector<vector<int>>ans;
    vector<int>vis;
    void helper(vector<int>& nums){
        if(list.size()==n){
            ans.push_back(list);
            return;
        }

        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            vis[i]=1;
            list.push_back(nums[i]);
            helper(nums);
            list.pop_back();
            vis[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vis.assign(n,0);
        helper(nums);
        return ans;
    }
};