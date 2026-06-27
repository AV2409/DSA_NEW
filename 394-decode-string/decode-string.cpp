class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans;
        stack<string> st;
        int i = n - 1;
        while (i >= 0) {
            if (s[i] == ']') {
                string x(1, s[i]);
                st.push(x);
                i--;
            } else if (isalpha(s[i])) {
                string x(1, s[i]);
                st.push(x);
                i--;
            }

            else if (s[i] == '[') {
                i--;
                string num = "";
                while (i >= 0 && isdigit(s[i])) {
                    num += s[i];
                    i--;
                }
                reverse(num.begin(), num.end());
                int ss = stoi(num);

                string str;
                while (!st.empty() && st.top() != "]") {
                    str += st.top();
                    st.pop();
                }
                st.pop();
                string decoded;

                for (int i = 0; i < ss; i++)
                    decoded += str;

                st.push(decoded);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};