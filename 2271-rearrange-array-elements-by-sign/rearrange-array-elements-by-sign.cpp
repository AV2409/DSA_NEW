class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        for(i=0;i<n;i++){
            if(nums[i]>0) break;
        }
        for(j=0;j<n;j++){
            if(nums[j]<0) break;
        }
        bool flag=1;
        vector<int>ans;
        while(i<n&&j<n){
            if(flag){
                ans.push_back(nums[i++]);
                while(i<n&&nums[i]<0)i++;
            }
            else{
                ans.push_back(nums[j++]);
                while(j<n&&nums[j]>0) j++;
            }
            flag=!flag;
        }
        if(i<n) ans.push_back(nums[i]);
        else ans.push_back(nums[j]);
        return ans;
    }
};