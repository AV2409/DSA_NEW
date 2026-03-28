class Solution {
public:
    void f(int op, int cl, string& s, vector<string>& ans, int n) {
        if (op > n || cl > n)
            return;
        if (cl > op)
            return;
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (op == cl) {
            s += '(';
            f(op + 1, cl, s, ans, n);
            s.pop_back();
        } else {
            s+='(';
            f(op + 1, cl, s, ans, n);
            s.pop_back();
            s+=')';
            f(op, cl+1, s, ans, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        f(0,0,s,ans,n);
        return ans;
    }
};