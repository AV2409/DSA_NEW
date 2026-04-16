class Solution {
public:
    vector<int> prevse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
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
    int sumSubarrayMins(vector<int>& arr) { 
        const int MOD = 1e9 + 7; 
        int n=arr.size();
        vector<int> pse=prevse(arr);
        vector<int> nse=nextse(arr);
        int ans=0;
        for(int i=0;i<n;i++){
            long long x;
            long long y;
            x=i-pse[i];
            y=nse[i]-i;

            long long cnt=x*y*1LL;
            ans=(ans+(cnt*arr[i])%MOD)%MOD;
        }
        return ans;
    }
};