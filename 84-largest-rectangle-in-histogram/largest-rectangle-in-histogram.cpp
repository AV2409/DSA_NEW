class Solution
{
public:
    vector<int> next_smaller(vector<int> arr, int n)
    {
        stack<int> st;
        vector<int> arr1(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                arr1[i] = n;
            }

            else
            {
                arr1[i] = st.top();
            }

            st.push(i);
        }

        return arr1;
    }

    vector<int> prev_smaller(vector<int> arr, int n)
    {
        stack<int> st;
        vector<int> arr1(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                arr1[i] = -1;
            }

            else
            {
                arr1[i] = st.top();
            }

            st.push(i);
        }

        return arr1;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n=heights.size();
        vector<int> next = next_smaller(heights, n);
        vector<int> prev = prev_smaller(heights, n);
        int area=0;
        int temp;
        for(int i=0;i<n;i++){
            temp=heights[i]*(next[i]-prev[i]-1);
            area=max(area,temp);
        }
        return area;
    }
};