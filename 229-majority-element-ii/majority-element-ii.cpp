class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums;
        if(n==2){
            if(nums[0]==nums[1]) return {nums[0]};
            return nums;
        }
        int ele1;
        int cnt1=0;
        int ele2;
        int cnt2=0;

        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=ele2){
                ele1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0&&nums[i]!=ele1){
                ele2=nums[i];
                cnt2=1;
            }
            else if(ele1==nums[i]){
                cnt1++;
            }

            else if(ele2==nums[i]){
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        int x1=0;
        int x2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1) x1++;
            if(nums[i]==ele2) x2++;
        }
        vector<int>ans;
        if(x1>n/3) ans.push_back(ele1);
        if(x2>n/3) ans.push_back(ele2);
        return ans;

    }
};