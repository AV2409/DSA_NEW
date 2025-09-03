class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int preSum=0;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            preSum+=nums[i];
            if(preSum==k){
                cnt++;
            }
            if(mp.find(preSum - k)!=mp.end()){
                cnt+=mp[preSum-k];
            }
            mp[preSum]++;
        }
        return cnt;
    }
};