class Solution {
public:
    int start = 0;
    int maxLen = 1;

    void expand(int left, int right, string& s) {

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                maxLen = len;
                start = left;
            }
            left--;
            right++;
        }
    }
    string longestPalindrome(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < s.size(); i++) {
            expand(i, i, s);
            expand(i, i + 1, s);
        }
        return s.substr(start, maxLen);
    }
};