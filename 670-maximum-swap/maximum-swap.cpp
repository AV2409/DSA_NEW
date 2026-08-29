class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);

        // Last occurrence of each digit
        vector<int> last(10, -1);

        for (int i = 0; i < n.size(); i++) {
            last[n[i] - '0'] = i;
        }

        // Find the first position where we can improve
        for (int i = 0; i < n.size(); i++) {
            int curr = n[i] - '0';

            // Try the largest digit first
            for (int d = 9; d > curr; d--) {
                if (last[d] > i) {
                    swap(n[i], n[last[d]]);
                    return stoi(n);
                }
            }
        }

        return num;
    }
};