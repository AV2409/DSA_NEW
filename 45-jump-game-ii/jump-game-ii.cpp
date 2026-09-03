class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int farthest=0;
        int jumps=0;
        while(farthest<n-1){
            int newfar=farthest;
            int r=farthest;
            for(int i=l;i<=farthest;i++){
                newfar=max(newfar,i+nums[i]);
            }
            if(newfar>farthest) {
                jumps++;
                farthest=newfar;
            }
            l=r+1;
        }
        return jumps;
    }
};