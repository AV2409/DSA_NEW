class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n)
            return "0";
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char cc = num[i];
            while (!st.empty() && st.top() > cc && k > 0) {
                st.pop();
                k--;
            }
            if (st.empty() && cc == '0')
                continue;
            st.push(cc);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        if (ans == "")
            return "0";

        reverse(ans.begin(), ans.end());

        return ans;
    }
};