class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int x=n-1;
        int dist=0;
        for(int i=0;i<n-1;i++){
            if(i>dist) return false;
            dist=max(dist,nums[i]+i);
            if(dist>=x) return true;
        }
        if(dist>=x) return true;
        else return false;
    }
};