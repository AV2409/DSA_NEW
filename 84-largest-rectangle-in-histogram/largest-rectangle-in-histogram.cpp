class Solution {
public:
    vector<int>prevSmaller(vector<int>& heights){
        stack<int>st;
        int n=heights.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;

    }

    vector<int>nextSmaller(vector<int>& heights){
        stack<int>st;
        int n=heights.size();
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i]=n;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;

    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev=prevSmaller(heights);
        vector<int>next=nextSmaller(heights);
        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(next[i]-prev[i]-1));
        }
        return ans;
    }
};