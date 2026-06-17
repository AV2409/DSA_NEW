class Solution {
public:
    int n;
    vector<int> frees;
    vector<vector<vector<int>>> dp;
    int f(int idx, int taken, int budget,vector<vector<int>>& items) {
        if (idx >= n) {
            return 0;
        }
        if (dp[idx][taken][budget] != -1)
            return dp[idx][taken][budget];

        int price = items[idx][1];

        // not take this time
        int notTake = f(idx + 1, 0, budget, items);

        int take = 0;
        if (price <= budget) {
            take = 1 + f(idx, 1, budget - price, items);
            if (!taken)
                take += frees[idx];
        }

        return dp[idx][taken][budget] = max(take, notTake);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        n = items.size();
        frees.assign(n, 0);
        dp.assign(n + 1, vector<vector<int>>(2, vector<int>(budget+1, -1)));
        for (int i = 0; i < n; i++) {
            int f = items[i][0];
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (items[j][0] % f == 0)
                    frees[i]++;
            }
        }

        return f(0, 0, budget, items);
    }
};