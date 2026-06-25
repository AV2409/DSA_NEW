class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) sum-=1;
            else sum+=1;

            int req=sum;
            if(mp.count(req)){
                res=max(res,i-mp[req]);
            }
            else mp[req]=i;
        }
        return res;
    }
};