class Solution {
public:
    int calculate(string s) {
        stack<long long> st;
        int n = s.size();
        int prevOp = '+';
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ')
                continue;
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                prevOp = s[i];
            } else {
                long long num = 0;

                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;

                if (prevOp == '+') {
                    st.push(num);
                }
                if (prevOp == '-') {
                    st.push(-num);
                }
                if (prevOp == '*') {
                    int top=st.top();
                    st.pop();
                    st.push(top*num);
                }
                if (prevOp == '/') {
                    int top=st.top();
                    st.pop();
                    st.push(top/num);
                }
            }
        }
        long long ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};