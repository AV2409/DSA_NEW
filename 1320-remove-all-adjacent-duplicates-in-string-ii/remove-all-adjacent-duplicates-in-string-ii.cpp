class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (char c : s) {
            if (st.empty() || st.top().first != c)
                st.push({c, 1});
            else if (st.top().first == c) {
                if (st.top().second == k - 1) {
                    st.pop();
                } else {
                    auto temp = st.top();
                    st.pop();
                    st.push({c, temp.second + 1});
                }
            }
        }

        string ans = "";
        while (!st.empty()) {
            for (int i = 0; i < st.top().second; i++)
                ans += st.top().first;
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};