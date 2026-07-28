class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0;
        int r=n-1;
        int ans=0;
        int lmax=0;
        int rmax=0;
        while(l<r){
            if(height[l]<=height[r]){
                lmax=max(height[l],lmax);
                ans+=lmax-height[l];
                l++;
            }
            else {
                rmax=max(height[r],rmax);
                ans+=rmax-height[r];
                r--;
            }
        }
        return ans;
    }
};