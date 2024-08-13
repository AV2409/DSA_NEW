class Solution {
private:
    int validchar(char& ch) {
        if (ch >= 'a' && ch <= 'z')
            return 1;
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
            return 1;

            
        }
        if (ch >= '0' && ch <= '9')
                return 1;

        return 0;
    }

public:
    bool isPalindrome(string s) {

        int st = 0;
        int end = s.length() - 1;

        while (st < end) {
            while (st < end && validchar(s[st]) == 0) {
                st++;
            }

            while (st < end && validchar(s[end]) == 0) {
                end--;
            }

            if (st < end && s[st] != s[end]) {

                return false;

            }

            else {

                st++;
                end--;
            }
        }
        return true;
    }
};