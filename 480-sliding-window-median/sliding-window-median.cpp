class Solution {
public:

    multiset<int> low, high;
    void balance() {
        while (low.size() > high.size() + 1) {
            high.insert(*prev(low.end()));
            low.erase(prev(low.end()));
        }

        while (low.size() < high.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }

    void insert(int num) {
        if (low.empty() || num <= *prev(low.end()))
            low.insert(num);
        else
            high.insert(num);

        balance();
    }

    void remove(int num) {
        auto it = low.find(num);
        if (it != low.end())
            low.erase(it);
        else
            high.erase(high.find(num));

        balance();
    }

    double median(int k) {
        if (k & 1)
            return *prev(low.end());
        return ((double)*prev(low.end()) + *high.begin()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        for (int i = 0; i < k; i++)
            insert(nums[i]);

        ans.push_back(median(k));

        for (int i = k; i < nums.size(); i++) {
            remove(nums[i - k]);
            insert(nums[i]);
            ans.push_back(median(k));
        }
        return ans;
    }
};