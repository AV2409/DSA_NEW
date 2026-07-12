class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        int cnt = 0;
        for (char ch : t) {
            if (hash[ch] == 0)
                cnt++;
            hash[ch]++;
        }

        int l = 0;
        int r = 0;
        int n = s.size();
        int cnt2 = 0;
        int minLen = INT_MAX;
        int st = -1;
        while (r < n) {
            hash[s[r]]--;
            if (hash[s[r]] == 0)
                cnt2++;
            while (cnt2 == cnt) {
                int len = r - l + 1;
                if (len < minLen) {
                    minLen = len;
                    st = l;
                }
                if (hash[s[l]] == 0)
                    cnt2--;
                hash[s[l]]++;
                l++;
            }
            r++;
        }
        if (minLen == INT_MAX)
            return "";
        return s.substr(st, minLen);
    }
};