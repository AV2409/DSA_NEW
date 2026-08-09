class Solution {
public:
    int ans=0;
    void helper(int i,vector<int>& nums,int x){
        if(i<0){
            ans+=x;
            return;
        }

        //pick
        helper(i-1,nums,x^nums[i]);
        //notpick
        helper(i-1,nums,x);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        helper(n-1,nums,0);
        return ans;
    }
};