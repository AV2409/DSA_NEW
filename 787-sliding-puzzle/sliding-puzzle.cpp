class Solution {
public:
    string encode(vector<vector<int>>& board) {
        string s;
        for (auto& row : board)
            for (int x : row)
                s += char(x + '0');
        return s;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<tuple<int, int, vector<vector<int>>>> q;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0)
                    q.push({i, j, board});
            }
        }

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        int ans = 0;

        unordered_set<string> vis;
        string state = encode(board);
        vis.insert(state);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [x, y, bb] = q.front();
                q.pop();

                string curr = encode(bb);
                if (curr == "123450")
                    return ans;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < 2 && ny < 3) {

                        swap(bb[x][y], bb[nx][ny]);
                        string state = encode(bb);
                        if (!vis.count(state)) {
                            vis.insert(state);
                            q.push({nx, ny, bb});
                        }
                        swap(bb[x][y], bb[nx][ny]);
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};