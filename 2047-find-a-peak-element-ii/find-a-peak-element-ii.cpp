class Solution {
public:
    int findMax(vector<int>&arr){
        int ans=0;
        int maxi=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi=arr[i];
                ans=i;
            }
        }
        return ans;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans(2);
        int l=0;
        int h=m-1;
        while(l<=h){
            int mid=(l+h)/2;
            int col=findMax(mat[mid]);
            int top=-1;
            int bottom=-1;

            if(mid-1>=0) top=mat[mid-1][col];
            if(mid+1<m) bottom=mat[mid+1][col];

            if(mat[mid][col]>top && mat[mid][col]>bottom){
                ans={mid,col};
                return ans;
            }
            else if(mat[mid][col]<=top) h=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};