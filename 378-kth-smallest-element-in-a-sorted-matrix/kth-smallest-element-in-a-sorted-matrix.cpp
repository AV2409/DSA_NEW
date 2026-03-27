class Solution {
public:

    bool isPossible(vector<vector<int>>& m,int ans,int k){
        int n=m.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j]<=ans) cnt++;
                if(cnt==k) return true;
            }
        }
        return false;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l=matrix[0][0];
        int n=matrix.size();
        int h=matrix[n-1][n-1];
        int mid;
        int ans;
        while(l<=h){
            int mid=(l+h)/2;
            if(isPossible(matrix,mid,k)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};