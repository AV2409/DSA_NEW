class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int area=0;

        while(l<r){
            int temp=(r-l)*min(height[l],height[r]);
            area=max(area,temp);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return area;
    }
};