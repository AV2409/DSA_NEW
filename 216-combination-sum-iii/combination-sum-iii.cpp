class Solution {
public:
    void f(int k, int n, int i, vector<int>& list, vector<vector<int>>& ans) {
        if (k == 0 && n == 0) {
            ans.push_back(list);
            return;
        }
        if (k <= 0 || n <= 0 || i == 10)
            return;

        for (int idx = i; idx <= 9; idx++) {
            list.push_back(idx);
            f(k - 1, n - idx, idx + 1, list, ans);
            list.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> list;
        vector<vector<int>> ans;
        f(k, n, 1, list, ans);
        return ans;
    }
};