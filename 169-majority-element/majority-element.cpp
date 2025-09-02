class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int cnt=0;

        int n=nums.size();

        for(int i=0;i<n;i++){
            if(cnt==0){
                ele=nums[i];
                cnt=1;
            }
            else if(nums[i]==ele) cnt++;
            else cnt--;
        }
        int x=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele) x++;
        }

        if(x>n/2) return ele;
        return -1;
    }
};