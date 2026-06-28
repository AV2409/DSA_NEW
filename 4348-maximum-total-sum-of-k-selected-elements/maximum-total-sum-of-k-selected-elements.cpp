class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int x:nums){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }
        long long ans=0;
        stack<int>st;
        while(!pq.empty()){
            int num=pq.top();
            pq.pop();
            st.push(num);
        }
        while(!st.empty()){
            
            int num=st.top();
            st.pop();
            ans=ans+max(1LL*num,1LL*num*mul);
            mul--;
        }
        return ans;
    }
};