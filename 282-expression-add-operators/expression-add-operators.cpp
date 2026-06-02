class Solution {
public:
    vector<string> ans;
    void solve(string& num, int target, int idx, long long curr, long long prev,
               string expr) {

        if (idx == num.size()) {
            if (curr == target)
                ans.push_back(expr);
            return;
        }

        for (int j = idx; j < num.size(); j++) {
            if (j > idx && num[idx] == '0')
                break;

            string part = num.substr(idx, j - idx + 1);
            long long x = stoll(part);

            if (idx == 0) {
                // First number: no operator before it
                solve(num, target, j + 1, x, x, part);
            } else {
                // +
                solve(num, target, j + 1, curr + x, x, expr + "+" + part);

                // -
                solve(num, target, j + 1, curr - x, -x, expr + "-" + part);

                // *
                solve(num, target, j + 1, curr - prev + prev * x, prev * x,
                      expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        solve(num, target, 0, 0, 0, "");
        return ans;
    }
};