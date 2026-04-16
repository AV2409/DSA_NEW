class Solution {
public:
    int find(vector<int>& heights) {
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        
        vector<int>arr(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') arr[j]++;
                else arr[j]=0;
            }
            int temp=find(arr);
            ans=max(ans,temp);
        }
        return ans;
        
    }
};