class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int x : asteroids) {
            if (st.empty()) {
                st.push(x);
            } else if (x > 0) {
                st.push(x);
            } else {
                int y = x;
                while (!st.empty() && st.top() * y < 0) {
                    int stTop = st.top();
                    if (stTop > abs(y)) {
                        y = 0;
                    } else if (stTop == abs(y)) {
                        y = 0;
                        st.pop();
                    } else {
                        st.pop();
                    }
                }
                if (y != 0) {
                    st.push(y);
                }
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};