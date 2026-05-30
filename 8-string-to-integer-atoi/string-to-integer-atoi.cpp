class Solution {
public:
    void helper(string s, int idx, long long& ans) {
        if (idx == s.size())
            return;

        if(ans>=INT_MAX || ans<=INT_MIN) return;
        if (s[idx] >= '0' && s[idx] <= '9') {
            long long dig = s[idx] - '0';
            ans = ans * 10 + dig;
        } else
            return;
        helper(s, idx + 1, ans);
    }
    int myAtoi(string s) {
        long long ans = 0;
        int idx = 0;
        int n = s.size();
        while (idx < n && s[idx] == ' ') {
            idx++;
        }
        bool neg = false;
        if (idx < n && s[idx] == '-') {
            neg = true;
            idx++;
        }

        else if (idx < n && s[idx] == '+') {
            idx++;
        }

        if (idx < n && s[idx] >= '0' && s[idx] <= '9') {
            helper(s, idx, ans);
        }

        if (neg)
            ans = -ans;

        if (ans <= INT_MIN)
            return INT_MIN;
        if (ans >= INT_MAX)
            return INT_MAX;

        return ans;
    }
};