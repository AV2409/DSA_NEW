class Solution {
public:

    bool isPossible(int mid,vector<int>& nums, int k){
        int temp=1;
        int sum=0;

        for(int n:nums){
            if(sum+n>mid){
                temp++;
                sum=n;
                if(temp>k) return false;
            }
            else{
                sum+=n;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        int mid=(low+high)/2;
        while(low<=high){
            
            if(isPossible(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            mid=(low+high)/2;
        }
        return ans;
    }
};