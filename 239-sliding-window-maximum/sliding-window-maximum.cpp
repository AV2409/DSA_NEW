class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            while(!dq.empty() && nums[dq.back()]<=nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        int r = k;
        int l = 0;
        while (r < n) {
            while(!dq.empty() && nums[dq.back()]<=nums[r]) dq.pop_back();
            dq.push_back(r);
            r++;
            l++;
            while(!dq.empty() && dq.front()<l) dq.pop_front();
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};