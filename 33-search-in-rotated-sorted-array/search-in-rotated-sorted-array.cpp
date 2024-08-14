class Solution {
private:
    int get_pivot(vector<int> v) {
        int size = v.size();
        int st = 0;
        int end = size - 1;
        int mid = st + (end - st) / 2;

        while (st < end) {

            if (v[st] <= v[end])
                return st;

            if (v[mid] >= v[0])
                st = mid + 1;

            else
                end = mid;

            mid = st + (end - st) / 2;
        }
        return st;
    }

    int solve(vector<int>& v, int target, int st, int end) {
        int mid = st + (end - st) / 2;

        while (st <= end) {

            if (v[mid] == target)
                return mid;

            else if (v[mid] > target)
                end = mid - 1;

            else
                st = mid + 1;

            mid = st + (end - st) / 2;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {

        int st = 0;
        int end = nums.size() - 1;
        int pivot = get_pivot(nums);
        if (nums[pivot] == target)
            return pivot;

        if (pivot==0)
            return solve(nums, target, st, end);
        if (target >= nums[st] && target <= nums[pivot - 1])
            return solve(nums, target, st, pivot - 1);

        else
            return solve(nums, target, pivot, end);

        return -1;
    }
};