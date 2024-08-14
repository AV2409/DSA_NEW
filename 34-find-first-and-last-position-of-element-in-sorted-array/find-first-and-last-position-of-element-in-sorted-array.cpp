class Solution {

private:
    int first(vector<int> v, int target) {
        int st = 0;
        int end = v.size() - 1;
        int mid = st + (end - st) / 2;
        int ans = -1;

        while (st <= end) {

            if (v[mid] == target) {
                ans = mid;
                end = mid - 1;
            }

            else if (v[mid] > v[0] && v[mid] > target)
                end = mid - 1;

            else
                st = mid + 1;

            mid = st + (end - st) / 2;
        }
        return ans;
    }

    int last(vector<int> v, int target) {
        int st = 0;
        int end = v.size() - 1;
        int mid = st + (end - st) / 2;
        int ans = -1;

        while (st <= end) {

            if (v[mid] == target) {
                ans = mid;
                st = mid + 1;
            }

            else if (v[mid] > v[0] && v[mid] > target)
                end = mid - 1;

            else
                st = mid + 1;

            mid = st + (end - st) / 2;
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans;
        int f = first(nums, target);
        int l = last(nums, target);
        ans.push_back(f);
        ans.push_back(l);
        return ans;
    }
};