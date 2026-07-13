class Solution {
public:
    bool isPossible(vector<int>& nums, int k,int mid){
        int sum=0;
        int cnt=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                sum=nums[i];
                cnt++;
            }
            if(cnt>k) return false;
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            // cout<<mid;
            if(isPossible(nums,k,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};