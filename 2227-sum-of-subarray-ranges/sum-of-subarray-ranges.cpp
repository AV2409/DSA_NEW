class Solution {
    private:
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

    vector<int> prevge(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
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

    vector<int> nextge(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
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
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> pse=prevse(nums);
        vector<int> nse=nextse(nums);

        vector<int> pge=prevge(nums);
        vector<int> nge=nextge(nums);
        long long mini=0;
        long long maxi=0;
        for(int i=0;i<n;i++){
            long long x;
            long long y;
            x=i-pse[i];
            y=nse[i]-i;

            long long cnt=x*y*1LL;
            mini=mini+cnt*nums[i];

            long long a;
            long long b;
            a=i-pge[i];
            b=nge[i]-i;

            long long cnt1=a*b*1LL;
            maxi=maxi+cnt1*nums[i];

        }
        return maxi-mini;
    }
};