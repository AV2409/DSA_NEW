class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> mp = {
            {1, "I"},   {5, "V"},    {10, "X"},   {50, "L"}, {100, "C"},
            {500, "D"}, {1000, "M"}, {4, "IV"},   {9, "IX"}, {40, "XL"},
            {90, "XC"}, {400, "CD"}, {900, "CM"},
        };
        vector<int> arr = {1,  4,   5,   9,   10,  40,  50,
                           90, 100, 400, 500, 900, 1000};
        string ans = "";
        while (num > 0) {
            auto ub = upper_bound(arr.begin(), arr.end(), num);
            int idx = ub - arr.begin();
            idx--;

            int nn = arr[idx];
            int times = num / nn;
            string s = mp[nn];
            while (times--) {
                ans += s;
            }

            num %= nn;
        }

        return ans;
    }
};