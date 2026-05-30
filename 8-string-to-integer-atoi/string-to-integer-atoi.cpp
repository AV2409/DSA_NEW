class Solution {
public:
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
            for (int i = idx; i < n; i++) {
                if (ans >= INT_MAX || ans <= INT_MIN)
                    break;
                if (s[i] >= '0' && s[i] <= '9') {
                    long long dig = s[i] - '0';
                    ans = ans * 10 + dig;
                } 
                else {
                    break;
                }
            }
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