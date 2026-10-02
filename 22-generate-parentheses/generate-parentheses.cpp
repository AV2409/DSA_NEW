class Solution {
public:
    string list;
    vector<string> ans;
    void f(int op, int cl) {
        if (op == 0 && cl == 0) {
            ans.push_back(list);
            return;
        }

        if (op) {
            list += '(';
            f(op - 1, cl);
            list.pop_back();
        }

        if(cl && cl>op) {
            list += ')';
            f(op, cl-1);
            list.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        f(n,n);
        return ans;
    }
};