class Solution {
vector<int> next_smaller(vector<int> arr)
{
    int n = arr.size();
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

vector<int> prev_smaller(vector<int> arr)
{
    int n = arr.size();
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

int find_area(vector<int> arr)
{
    int n = arr.size();
    vector<int> next = next_smaller(arr);
    vector<int> prev = prev_smaller(arr);

    int area = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        temp = arr[i] * (next[i] - prev[i] - 1);
        area = max(area, temp);
    }

    return area;
}

public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> temp(m,vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                    temp[i][j]=matrix[i][j]-'0';
            }
        }
        int area = find_area(temp[0]);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[i][j] ==0) {
                    temp[i][j] =0;
                } else {
                    temp[i][j] += temp[i - 1][j];
                }
            }
            area = max(area, find_area(temp[i]));
        }
        return area;
    }
};