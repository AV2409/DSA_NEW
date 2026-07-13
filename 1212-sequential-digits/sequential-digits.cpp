class Solution {
public:
    int f(int num) {
        int cnt = 0;
        while (num > 0) {
            num /= 10;
            cnt++;
        }
        return cnt;
    }

    vector<int> sequentialDigits(int low, int high) {
        int n1 = f(low);
        int n2 = f(high);
        vector<int> ans;
        for (int digits = n1; digits <= n2; digits++) {
            int x = 0;
            int adder = 0;
            for (int i = 1; i <= digits; i++) {
                x = x * 10 + i;
                adder = adder * 10 + 1;
            }

            for (int i = 1; i <= 9 - digits + 1; i++) {
                if (x >= low && x <= high) {
                    ans.push_back(x);
                }

                x += adder;
            }
        }

        return ans;
    }
};