class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long total=accumulate(nums.begin(),nums.end(),0ll);
        long long preSum=0;
        long long endSum=0;
        int n=nums.size();
        int i=0;
        for(;i<n-1;i++){
            if(nums[i+1]>nums[i]) preSum+=nums[i];
            else break;
        }
        preSum+=nums[i];
        endSum=total-preSum;
        if(i!=0) endSum+=nums[i];
        cout<<i<<endl;
        cout<<preSum<<" "<<total-preSum;

        if(preSum>endSum) return 0;
        if(preSum<endSum) return 1;
        return -1;

    }
};