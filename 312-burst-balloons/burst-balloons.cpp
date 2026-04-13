class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(1);
        int maxi = 0;
        for (int x : nums) {
            arr.push_back(x);
            maxi = max(x, maxi);
        }

        arr.push_back(1);
        int m = arr.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 2; j <= m - 1; j++) {
                int temp = -1;
                for (int k = i + 1; k < j; k++) {
                    int cc = arr[i] * arr[k] * arr[j] +dp[i][k] + dp[k][j];
                    temp = max(temp, cc);
                }
                dp[i][j] = temp;
            }
        }

        return dp[0][m-1];
    }
};