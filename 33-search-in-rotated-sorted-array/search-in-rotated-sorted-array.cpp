class Solution {
public:
int Bsearch(vector<int>& nums, int target,int l,int r) {
    while (l <= r) {
        int mid = (l + r) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int pivotEle(vector<int>& nums) {
    int n = nums.size();
    int r = n - 1;
    int l = 0;

    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > nums[r]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return r;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (nums[0] > target && nums[n - 1] < target) {
        return -1;
    }

    int r = n - 1;
    int l = 0;
    int pvt=pivotEle(nums);
    int ans=-1;
    if(target>nums[r]){
        ans=Bsearch(nums,target,0,pvt-1);
    }
    else{
        ans=Bsearch(nums,target,pvt,r);
    }
    return ans;
}
};