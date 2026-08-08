class Solution {
public:
    bool isPossible(int mid,vector<int>& nums, int k){
        int num=1;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+nums[i]>mid){
                num++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
            if(num>k) return false;
        }
        return num<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;

            if(isPossible(mid,nums,k)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};