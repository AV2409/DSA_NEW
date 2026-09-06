class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();

        int k=(m+n+2)/2;
        priority_queue<int>pq;
        for(int x:nums1){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }

        for(int x:nums2){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }

        if((m+n)%2) return pq.top();
        int a1=pq.top();
        pq.pop();
        int a2=pq.top();
        return (a1+a2)/2.0;
    }
};