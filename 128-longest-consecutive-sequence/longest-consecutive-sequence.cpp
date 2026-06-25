class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        int len=0;

        for(int i=0;i<n;i++){
            if(st.count(nums[i]) && st.count(nums[i]-1)==0){
                int temp=0;
                while(st.count(nums[i]+temp)) {
                    st.erase(nums[i]+temp);
                    temp++;
                }
                len=max(len,temp);
            }
        }
        return len;

    }
};