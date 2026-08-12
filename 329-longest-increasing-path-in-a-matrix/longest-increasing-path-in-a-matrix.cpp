class Solution {
public:
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    int ans=1;
    int m;
    int n;
    vector<vector<int>>dp;
    int dfs(int i,int j,vector<vector<int>>& matrix){
        
        if(dp[i][j]!=-1) return dp[i][j];
        int len=1;
        int temp=matrix[i][j];
        matrix[i][j]=-1;

        for(int dir=0;dir<4;dir++){
            int nx=i+dx[dir];
            int ny=j+dy[dir];

            if(nx>=0 && ny>=0 && nx<m && ny<n && matrix[nx][ny]>temp){
                len=max(len,1+dfs(nx,ny,matrix));
                ans=max(ans,len);
            }
        }
        matrix[i][j]=temp;
        return dp[i][j]=len;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        dp.assign(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(i,j,matrix);
            }
        }
        return ans;
    }
};