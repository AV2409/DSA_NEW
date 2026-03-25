class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st1;
        st1.push(nums[n-1]);
        

        for(int i=n-2;i>=0;i--){
            while(!st1.empty()&&st1.top()<=nums[i]) st1.pop();
            st1.push(nums[i]);
        }
        vector<int> ans(n);
        st1.push(nums[n-1]);
        for(int i=n-1;i>=0;i--){
            while(!st1.empty()&&st1.top()<=nums[i]) st1.pop();

            if(st1.empty()) ans[i]=-1;
            else ans[i]=st1.top();

            st1.push(nums[i]);
        }
        return ans;
    }
};