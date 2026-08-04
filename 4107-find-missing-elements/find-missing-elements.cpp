class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int>st;
        for(int x:nums){
            st.insert(x);
        }

        int x=*st.begin();
        int end=*prev(st.end());
        vector<int>ans;
        for(int i=x;i<=end;i++){
            if(!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};