class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ps(n);
        vector<int> ns(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] <= heights[st.top()])
                st.pop();
            if (st.empty())
                ps[i] = -1;
            else
                ps[i] = st.top();

            st.push(i);
        }

        stack<int> st1;
        for (int i = n-1; i >= 0; i--) {
            while (!st1.empty() && heights[i] <= heights[st1.top()])
                st1.pop();
            if (st1.empty())
                ns[i] = n;
            else
                ns[i] = st1.top();

            st1.push(i);
        }

        int ans=0;

        for (int i = 0; i < n; i++) {
            int ht=heights[i];
            int width=ns[i]-ps[i]-1;
            ans=max(ans,ht*width);
        }
        return ans;
    }
};