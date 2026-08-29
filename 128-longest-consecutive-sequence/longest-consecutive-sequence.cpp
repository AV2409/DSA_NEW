class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        st.insert(nums.begin(),nums.end());
        int maxLen=0;
        for(int x:nums){
            if(st.count(x-1)) continue;

            int num=x;
            int len=0;
            while(st.count(num)){
                st.erase(num);
                num=num+1;
                len++;
            }
            maxLen=max(len,maxLen);
        }
        return maxLen;
    }
};