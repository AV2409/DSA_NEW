class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int st=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j]==0)
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = 1 + dp[j];
                        parent[i] = j;
                    }
            }

            if(dp[i]>ans){
                st=i;
                ans=dp[i];
            }
        }
        vector<int>res;
        while(st!=-1){
            res.push_back(nums[st]);
            st=parent[st];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};