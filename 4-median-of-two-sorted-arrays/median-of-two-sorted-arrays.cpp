class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(m<n) return findMedianSortedArrays(nums2,nums1);

        int req=(m+n)/2;
        if((m+n)%2) req++;
        int tot=m+n;

        int l=req-n;
        int h=req;

        while(l<=h){
            int mid=(l+h)/2;
            int part1=mid;
            int part2=req-mid;

            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;

            if(part1-1>=0) l1=nums1[part1-1];
            if(part2-1>=0) l2=nums2[part2-1];
            if(part1<m) r1=nums1[part1];
            if(part2<n) r2=nums2[part2];

            if(l1<=r2 && l2<=r1){
                if(tot%2) return max(l1,l2);
                double ans=(max(l1,l2)+min(r1,r2))/2.0;
                return ans;
            }
            else if(l1>r2){
                h=mid-1;
            }
            else if(l2>r1){
                l=mid+1;
            }
        }
        return -1;

    }
};