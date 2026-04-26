class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n=nums.size();

        vector<int>inc(n);
        inc[0]=1;
        inc[n-1]=1;
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>maxi) inc[i]=1;
            maxi=max(maxi,nums[i]);
        }

        maxi=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>maxi) inc[i]=1;
            maxi=max(maxi,nums[i]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(inc[i]) ans.push_back(nums[i]);
        }
        return ans;
    }
};