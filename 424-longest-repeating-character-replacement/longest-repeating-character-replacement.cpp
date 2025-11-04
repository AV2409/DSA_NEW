class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int res = 0;
        int n = s.size();
        int maxf = 0;
        vector<int> hash(26, 0);
        while (r < n) {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            while ((r-l+1) - maxf > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};