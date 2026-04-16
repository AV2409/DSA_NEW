class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int lmax=0;
        int rmax=0;
        int ans=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]<lmax){
                    ans+=lmax-height[l];
                }
                
                lmax=max(lmax,height[l]);
                l++;
            }

            else{
                if(height[r]<rmax){
                    ans+=rmax-height[r];
                }
                
                rmax=max(rmax,height[r]);
                r--;
            }
        }
        return ans;
    }
};