class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        st.insert(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(st.count(num-1)) continue;
            st.erase(num);
            int cnt=1;
            while(!st.empty() && st.count(num+1)){
                num=num+1;
                st.erase(num);
                cnt++;
            }
            ans=max(ans,cnt);

        }
        return ans;
    }
};