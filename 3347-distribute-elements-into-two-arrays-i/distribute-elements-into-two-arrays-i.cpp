class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        int i=0;
        int j=0;
        for(int x=2;x<n;x++){
            if(arr1[i]>arr2[j]){
                arr1.push_back(nums[x]);
                i++;
            }
            else {
                arr2.push_back(nums[x]);
                j++;
            }
        }
        for(int x:arr2) arr1.push_back(x);
        return arr1;
    }
};