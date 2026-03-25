class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();

        vector<int>ans1(2*n);
        vector<int>arr(2*n);
        int n1=2*n;
        for(int i=0;i<n;i++){
            arr[i]=nums[i];
            arr[i+n]=nums[i];
        }
        stack<int>st1;
        st1.push(arr[n1-1]);
        ans1[n1-1]=-1;
        for(int i=n1-2;i>=0;i--){
            while(!st1.empty()&&st1.top()<=arr[i]) st1.pop();

            if(st1.empty()) ans1[i]=-1;
            else ans1[i]=st1.top();

            st1.push(arr[i]);
        }
        vector<int> ans(ans1.begin(), ans1.begin()+n);

        return ans;
    }
};