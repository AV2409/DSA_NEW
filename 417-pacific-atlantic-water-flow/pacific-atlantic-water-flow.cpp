class Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    int rows;
    int cols;

    void dfs(int x, int y, vector<vector<int>>& heights,
             vector<vector<int>>& vis) {
        vis[x][y] = 1;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && vis[nx][ny] == 0 && heights[nx][ny] >= heights[x][y]) {
                dfs(nx,ny,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
            dfs(i, 0, heights, pacific);

        for (int j = 0; j < cols; j++)
            dfs(0, j, heights, pacific);

        // Atlantic (bottom row + right column)
        for (int i = 0; i < rows; i++)
            dfs(i, cols - 1, heights, atlantic);

        for (int j = 0; j < cols; j++)
            dfs(rows - 1, j, heights, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};