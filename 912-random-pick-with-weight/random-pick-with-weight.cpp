class Solution {
public:
    vector<int> prefix;
    int total = 0;

    Solution(vector<int>& w) {
        for (int x : w) {
            total += x;
            prefix.push_back(total);
        }
    }

    int pickIndex() {
        int target = rand() % total + 1;

        return lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
    }
};