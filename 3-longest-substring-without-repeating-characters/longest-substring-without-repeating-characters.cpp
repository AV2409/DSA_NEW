class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int maxlen = 0;
        int n = s.length();
        int l = 0;
        int r = 0;
        int len = 0;
        int hash[255] = {0};
        while (r < n) {

            while (hash[s[r]] == 1) {
                hash[s[l]]--;
                l++;
            }

            hash[s[r]] = 1;

            len = r - l + 1;
            maxlen = max(maxlen, len);

            r++;
        }

        return maxlen;
    }
};