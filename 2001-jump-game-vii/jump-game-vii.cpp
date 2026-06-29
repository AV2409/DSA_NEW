class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        queue<int> q;
        q.push(0);

        vector<bool> vis(n, false);
        vis[0] = true;

        int farthest = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1)
                return true;

            int L = max(farthest, i + minJump);
            int R = min(n - 1, i + maxJump);

            for (int j = L; j <= R; j++) {
                if (s[j] == '0' && !vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }

            farthest = max(farthest, R + 1);
        }

        return false;
    }
};