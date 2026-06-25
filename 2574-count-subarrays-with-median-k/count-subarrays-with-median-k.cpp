class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int ans=0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        bool found=false;
        for (int x : nums) {
            if (x > k)
                sum++;
            else if (x < k)
                sum--;

            if (x == k)
                found = true;

            if (!found) {
                mp[sum]++;
            } else {
                ans += mp[sum];
                ans += mp[sum - 1];
            }
        }
        return ans;
    }
};