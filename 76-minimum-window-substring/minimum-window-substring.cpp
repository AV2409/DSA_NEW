class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        map<char, int> mp;
        for (char c : t)
            mp[c]++;

        int l = 0;
        int r = 0;
        int st = -1;
        int end = -1;
        int cnt = 0;
        int minl = INT_MAX;
        while (r < n1) {

            if (mp[s[r]] > 0)
                cnt++;
            mp[s[r]]--;

            while (cnt == n2) {
                if (r - l + 1 < minl) {
                    st = l;
                    end = r;
                    minl=r-l+1;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        string ans = "";
        if (st == -1 || end == -1)
            return ans;

        for (int i = st; i <= end; i++) {
            ans += s[i];
        }
        return ans;
    }
};