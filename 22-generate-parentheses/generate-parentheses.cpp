class Solution {
public:
    string s;
    vector<string> ans;

    void f(int open, int closed) {
        if (open == 0 && closed == 0) {
            ans.push_back(s);
            return;
        }

        if (open > 0) {
            s.push_back('(');
            f(open - 1, closed);
            s.pop_back();
        }

        if (closed > open) {
            s.push_back(')');
            f(open, closed - 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        f(n, n);
        return ans;
    }
};