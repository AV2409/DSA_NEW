class Solution {
public:
    int findPeak(vector<int>&arr){
        int n=arr.size();
        int l=0;
        int h=n-1;

        while(l<h){
            int mid=(l+h)/2;
            int prev=-1;
            int next=-1;
            if(mid-1>=0) prev=arr[mid-1];
            if(mid+1<n) next=arr[mid+1];
            if(arr[mid]>prev && arr[mid]>next) return mid;
            else if(arr[mid]>next) h=mid-1;
            else l=mid+1;
        }
        return l;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans(2);
        for(int i=0;i<m;i++){
            int col=findPeak(mat[i]);
            int top=-1;
            int bottom=-1;

            if(i-1>=0) top=mat[i-1][col];
            if(i+1<m) bottom=mat[i+1][col];

            if(mat[i][col]>top && mat[i][col]>bottom){
                ans={i,col};
                return ans;
            }
        }
        return ans;
    }
};