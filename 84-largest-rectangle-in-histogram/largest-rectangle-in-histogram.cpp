class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int idx = st.top();
                st.pop();

                int pse = -1;
                if (!st.empty())
                    pse = st.top();
                int nse = i;
                int width = nse - pse - 1;
                ans = max(ans, width * heights[idx]);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int idx = st.top();
            st.pop();

            int pse = -1;
            if (!st.empty())
                pse = st.top();
            int nse = n;
            int width = nse - pse - 1;
            ans = max(ans, width * heights[idx]);
        }
        return ans;
    }
};