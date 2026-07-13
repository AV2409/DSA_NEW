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

        f(idx + 1, n, k, list, ans);
        list.push_back(idx);
        f(idx + 1, n, k, list, ans);
        list.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> list;
        vector<vector<int>> ans;
        f(1, n, k, list, ans);
        return ans;
    }
};