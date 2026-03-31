class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        if (n2 > n1) return "";

        vector<int> needed(256, 0), have(256, 0);

        for (char c : t) needed[c]++;

        int cnt = t.size();
        int l = 0, start = 0, minLen = INT_MAX;

        for (int r = 0; r < n1; r++) {

            have[s[r]]++;

            if (needed[s[r]] > 0 && have[s[r]] <= needed[s[r]]) {
                cnt--;
            }

            while (cnt == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                have[s[l]]--;

                if (needed[s[l]] > 0 && have[s[l]] < needed[s[l]]) {
                    cnt++;
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};