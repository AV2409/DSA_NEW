class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>>ans;
        int tot=1<<nums.size();

        for(int num=0;num<tot;num++){
            vector<int>s;
            for(int i=0;i<nums.size();i++){
                if(num & 1<<i) s.push_back(nums[i]);
            }
            ans.push_back(s);
        }
        
        return ans;
    }
};