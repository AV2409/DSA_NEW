class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans;
        stack<string> st;
        stack<int> cnt;
        s += ']';
        st.push(string(1, '['));
        for (int i = 0; i <= n; i++) {
            if (isdigit(s[i])) {
                string num;
                while (i <= n && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                i--;
                int ss = stoi(num);
                cnt.push(ss);
            } else if (isalpha(s[i])) {
                string x;
                while (i <= n && isalpha(s[i])) {
                    x += s[i];
                    i++;
                }
                i--;
                // reverse(x.begin(),x.end());
                st.push(x);
            }

            else if (s[i] == '[') {
                st.push(string(1, s[i]));
            }

            else if (s[i] == ']') {
                int times = 1;
                if (!cnt.empty()) {
                    times = cnt.top();
                    cnt.pop();
                }

                vector<string> parts;

                while (!st.empty() && st.top() != "[") {
                    parts.push_back(st.top());
                    st.pop();
                }
                st.pop();

                reverse(parts.begin(), parts.end());

                string x;
                for (auto& str : parts)
                    x += str;

                string toPush;
                while (times--) {
                    toPush += x;
                }
                // reverse(toPush.begin(),toPush.end());
                st.push(toPush);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};