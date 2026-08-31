class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=0;
        int maxi=0;

        for(int i=1;i<n;i++){
            if(nums[i]<nums[mini]){
                mini=i;
            }

            if(nums[i]>nums[maxi]){
                maxi=i;
            }
        }

        int ff=max(maxi,mini)+1;
        int fb=(min(maxi,mini)+1)+n-max(maxi,mini);
        int bb=max(n-maxi,n-mini);
        // int bf=;
        return min({ff,fb,bb});
    }
};