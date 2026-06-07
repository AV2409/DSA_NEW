class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int left = (m + n + 1) / 2;
        int low = 0;
        int high = m;

        while (low <= high) {
            int m1 = (low + high) / 2;
            int m2 = left - m1;

            int l1 = INT_MIN;
            int r1 = INT_MAX;
            int l2 = INT_MIN;
            int r2 = INT_MAX;

            if (m1 - 1 >= 0)
                l1 = nums1[m1 - 1];
            if (m1 < m)
                r1 = nums1[m1];

            if (m2 - 1 >= 0)
                l2 = nums2[m2 - 1];
            if (m2 < n)
                r2 = nums2[m2];

            if (l1 > r2)
                high = m1 - 1;
            else if (l2 > r1)
                low = m1 + 1;

            else {
                if ((m + n) % 2)
                    return max(l1, l2);

                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }

        return 0;
    }
};