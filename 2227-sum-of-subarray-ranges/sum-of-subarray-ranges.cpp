class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>prevSmaller(n);
        vector<int>nextSmaller(n);

        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) prevSmaller[i]=-1;
            else prevSmaller[i]=st.top();

            st.push(i);
        }

        stack<int>st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && arr[st1.top()]>arr[i]){
                st1.pop();
            }
            if(st1.empty()) nextSmaller[i]=n;
            else nextSmaller[i]=st1.top();

            st1.push(i);
        }
        long long ans=0;

        for(int i=0;i<n;i++){
            int l=i-prevSmaller[i];
            int r=nextSmaller[i]-i;

            ans = (ans + 1LL * arr[i] * l * r);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector<int>prevGreater(n);
        vector<int>nextGreater(n);

        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()) prevGreater[i]=-1;
            else prevGreater[i]=st.top();

            st.push(i);
        }

        stack<int>st1;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && arr[st1.top()]<arr[i]){
                st1.pop();
            }
            if(st1.empty()) nextGreater[i]=n;
            else nextGreater[i]=st1.top();

            st1.push(i);
        }
        long long ans=0;

        for(int i=0;i<n;i++){
            int l=i-prevGreater[i];
            int r=nextGreater[i]-i;

            ans = (ans + 1LL * arr[i] * l * r);
        }
        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long maxi=sumSubarrayMaxs(nums);
        long long mini=sumSubarrayMins(nums);
        return maxi-mini;
    }
};