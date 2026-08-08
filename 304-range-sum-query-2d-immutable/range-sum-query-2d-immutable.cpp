class NumMatrix {
public:
    vector<vector<int>>pre;
    NumMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        pre.assign(row+1,vector<int>(col+1,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                
                int top=pre[i][j+1];
                int left=pre[i+1][j];

                pre[i+1][j+1] = matrix[i][j] + top + left - pre[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=pre[row2+1][col2+1]-pre[row1][col2+1]-pre[row2+1][col1]+pre[row1][col1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */