class Solution {
public:
    void f(int idx, int n, int k, vector<int>& list, vector<vector<int>>& ans) {
        if (list.size() == k) {
            ans.push_back(list);
            return;
        }
        if (idx > n) {

            return;
        }

        for (int i = idx; i <= n; i++) {
            // f(idx + 1, n, k, list, ans);

            list.push_back(i);
            f(i + 1, n, k, list, ans);
            list.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> list;
        vector<vector<int>> ans;
        f(1, n, k, list, ans);
        return ans;
    }
};