class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 0;
        int r = 0;
        int n = chars.size();
        int idx = 0;
        while (r < n) {
            r = l;
            while (r < n && chars[l] == chars[r])
                r++;
            int len = r - l;
            chars[idx] = chars[l];
            idx++;
            string ll = to_string(len);
            if (len > 1) {
                for (char c : ll) {
                    chars[idx] = c;
                    idx++;
                }
            }
            l = r;
        }

        return idx;
    }
};