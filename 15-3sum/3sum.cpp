class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int k=0;k<n;k++){
            int i=k+1;
            int j=n-1;
            while(i<j){
                int sum=nums[k]+nums[i]+nums[j];
                if(sum==0){
                    ans.push_back({nums[k],nums[i],nums[j]});
                    i++;
                    j--;
                    while(i<j && nums[i]==nums[i-1]) i++;
                    while(i<j && nums[j]==nums[j+1]) j--;
                }
                else if(sum<0) i++;
                else j--;
            }
            while(k+1<n && nums[k]==nums[k+1]) k++;

        }
        return ans;
    }
};