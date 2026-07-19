class Solution {
public:
    bool check(string& a, string& b) {
        if (a.size() + 1 != b.size())
            return false;

        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++; // skip one character in the longer string
            }
        }

        return i == a.size();
    }
    static bool comp(string& a, string& b) { return a.size() < b.size(); }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int lis = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            lis = max(lis, dp[i]);
        }
        return lis;
    }
};