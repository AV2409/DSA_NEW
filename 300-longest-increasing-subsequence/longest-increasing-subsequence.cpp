class Solution {
public:
    int find(vector<int>&arr,int key){
        int l=0;
        int r=arr.size();
        int mid;
        int ans=-1;
        while(l<=r){
            mid=(l+r)/2;
            if(arr[mid]>=key){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(nums[0]);
        int idx=0;
        for(int i=1;i<n;i++){
            if(arr[idx]<nums[i]){
                arr.push_back(nums[i]);
                idx++;
            }
            else{
                int posi=find(arr,nums[i]);
                arr[posi]=nums[i];
            }
        }
        return arr.size();
    }
};