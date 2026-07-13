class Solution {
public:
    void f(int i, int k, int target, vector<int>& cur,
           vector<vector<int>>& ans) {
        if (cur.size() == k && target == 0) {
            ans.push_back(cur);
            return;
        }

        if (i > 9)
            return;

        // Not Pick
        f(i + 1, k, target, cur, ans);
        // Pick
        if (target - i >= 0) {
            cur.push_back(i);
            f(i + 1, k, target - i, cur, ans);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        f(1, k, n, cur, ans);
        return ans;
    }
};