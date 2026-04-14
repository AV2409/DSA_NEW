class Solution {
public:
    
    int superEggDrop(int k, int n) {
        int eggs = k;
        int floors = n;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        for (int i = 1; i <= k; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for (int i = 1; i <= n; i++) {
            dp[1][i] = i;
            dp[0][i] = 1e9;
        }

        for (int i = 1; i <= eggs; i++) {
            for (int j = 1; j <= floors; j++) {
                int mini = 1e9;
                int low = 1, high = j;
                while (low <= high) {
                    int mid = (low + high) / 2;

                    int op1 = dp[i-1][mid-1];
                    int op2 = dp[i][j-mid];

                    int temp = 1 + max(op1, op2);
                    mini = min(mini, temp);

                    if (op1 > op2)
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
                dp[i][j] = mini;
            }
        }
        return dp[k][n];
    }
};