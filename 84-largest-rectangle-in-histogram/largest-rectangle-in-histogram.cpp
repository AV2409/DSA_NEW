class Solution {
public:
    vector<int> pse(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!(st.empty()) && (arr[st.top()] >= arr[i])) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nse(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!(st.empty()) && (arr[st.top()] >= arr[i])) {
                st.pop();
            }
            if (st.empty()) {
                ans[i] = n;
            } else {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = pse(heights);
        vector<int> right = nse(heights);

        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = heights[i] * (right[i] - left[i] - 1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};