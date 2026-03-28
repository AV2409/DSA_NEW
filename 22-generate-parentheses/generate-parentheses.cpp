class Solution {
public:
    void f(int op, int cl, string& s, vector<string>& ans, int n) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (op < n) {
            s += '(';
            f(op + 1, cl, s, ans, n);
            s.pop_back();
        }
        if (cl < op) {
            s += ')';
            f(op, cl + 1, s, ans, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        f(0, 0, s, ans, n);
        return ans;
    }
};