class Solution {
public:
    int prec(char ch) {
        if (ch == '/' || ch == '*')
            return 2;
        if (ch == '+' || ch == '-')
            return 1;
        return 3;
    }
    vector<string> convertToPostfix(string s) {
        string ans;
        stack<char> st;
        vector<string> postfix;

        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                string num;

                while (i < n && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }

                postfix.push_back(num);
                i--;
            } else if (s[i] == ' ')
                continue;
            else if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')') {

                while (!st.empty() && st.top() != '(') {
                    postfix.push_back(string(1, st.top()));
                    st.pop();
                }
                st.pop();
            } else {
                while (!st.empty() && st.top() != '(' &&
                       prec(st.top()) >= prec(s[i])) {
                    postfix.push_back(string(1, st.top()));
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            postfix.push_back(string(1, st.top()));
            st.pop();
        }
        return postfix;
    }
    int calculate(string s) {
        vector<string> exp = convertToPostfix(s);
        stack<int> st;
        int n = exp.size();
        for (int i = 0; i < n; i++) {
            if (exp[i] == "+" || exp[i] == "-"||exp[i] == "/"||exp[i] == "*") {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                if (exp[i] == "+")
                    st.push(n1 + n2);

                else if (exp[i] == "*")
                    st.push(n1 * n2);
                else if (exp[i] == "-")
                    st.push(n2 - n1);
                else
                    st.push(n2 / n1);
            }

            else {
                st.push(stoi(exp[i]));
            }
        }
        return st.top();
    }
};