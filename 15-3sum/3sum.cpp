class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[l]+nums[r]+nums[i];
                if(sum==0){
                    vector<int>temp={nums[i],nums[l],nums[r]};
                    st.insert(temp);
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
                else if(sum<0){
                    l++;
                }
                else if(sum>0){
                    r--;
                }
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};