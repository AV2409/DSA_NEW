class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int s=0;
        int e=rows*cols-1;
        int mid=s+(e-s)/2;
        int i,j;

        while(s<=e){
            i=mid/cols;
            j=mid%cols;
            if(matrix[i][j]==target) return true;

            else if(matrix[i][j]>target) e=mid-1;

            else s=mid+1;

            mid=s+(e-s)/2;
        }

        return false;
    }
};