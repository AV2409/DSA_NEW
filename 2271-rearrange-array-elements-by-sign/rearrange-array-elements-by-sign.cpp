class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        queue<int> pos;
        queue<int> neg; 
        vector<int>ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                pos.push(nums[i]);
            else
                neg.push(nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (i%2==0) {
                ans.push_back(pos.front());
                pos.pop();
            } else {
                ans.push_back(neg.front());
                neg.pop();
            }
        }
        return ans;
    }
};