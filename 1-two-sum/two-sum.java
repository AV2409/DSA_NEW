class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n=nums.length;
        int[] ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=nums[i]+nums[j];
                if(sum==target) {
                    ans=new int[]{i, j};
                    return ans;
                }
            }
        }
        // return ans;
        return new int[]{};
    }
}