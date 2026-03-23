class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int o=0;
        int z=0;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            if(nums[i]==0) z++;
            else o++;

            int diff=(z-o);
            if(diff==0) res=max(res,i+1);
            else{
                if(mp.find(diff)!=mp.end()) res=max(res,i-mp[diff]);
                else mp[diff]=i;
            }
        }
        return res;
    }
};