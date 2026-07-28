class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        st.insert(nums.begin(),nums.end());
        int ans=0;
        for(int x:nums){
            if(st.count(x-1)) continue;

            int cnt=0;
            int num=x;
            while(st.count(num)){
                cnt++;
                st.erase(num);
                num++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};