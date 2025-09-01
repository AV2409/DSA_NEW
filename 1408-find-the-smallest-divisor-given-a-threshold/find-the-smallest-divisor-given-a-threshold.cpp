class Solution {
public:
    bool isPossible(int mid,vector<int>& nums, int th){
        int sum=0;
        for(auto i:nums){
            int temp=ceil((double)i/mid);
            sum+=temp;
            if(sum>th) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid, nums,threshold)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};