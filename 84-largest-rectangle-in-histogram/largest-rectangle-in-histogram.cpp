class Solution {
public:
    vector<int> prevse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> nextse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = n;
            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse = prevse(heights);
        vector<int> nse = nextse(heights);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int ht = heights[i];
            int width = nse[i] - pse[i] - 1;
            ans = max(ans, ht * width);
        }
        return ans;
    }
};