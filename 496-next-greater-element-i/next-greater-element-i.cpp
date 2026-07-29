class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //{ele,idx}
        unordered_map<int,int>hash;
        int n2=nums2.size();
        vector<int>nextGt(n2);
        stack<int>st;
        for(int i=n2-1;i>=0;i--){
            hash[nums2[i]]=i;
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()) nextGt[i]=-1;
            else nextGt[i]=st.top();

            st.push(nums2[i]);
        }

        vector<int>ans;
        for(int x:nums1){
            int idx=hash[x];
            ans.push_back(nextGt[idx]);
        }
        return ans;

    }
};