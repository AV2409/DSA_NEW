class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Keep 3 largest numbers
        priority_queue<int, vector<int>, greater<int>> largest;

        // Keep 2 smallest numbers
        priority_queue<int> smallest;

        for (int x : nums) {
            largest.push(x);
            if (largest.size() > 3)
                largest.pop();

            smallest.push(x);
            if (smallest.size() > 2)
                smallest.pop();
        }

        vector<int> big, small;

        while (!largest.empty()) {
            big.push_back(largest.top());
            largest.pop();
        }

        while (!smallest.empty()) {
            small.push_back(smallest.top());
            smallest.pop();
        }
        long long prod1 = 1LL * big[0] * big[1] * big[2];
        long long prod2 = 1LL * small[0] * small[1] * big[2];
        return max(prod1, prod2);
    }
};