class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        st.insert(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        while(!st.empty()){
            int num = *prev(st.end());
            st.erase(num);
            int cnt=1;
            while(!st.empty() && st.count(num-1)){
                num=num-1;
                st.erase(num);
                cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};