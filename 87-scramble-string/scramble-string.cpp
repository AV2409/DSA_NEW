class Solution {
public:
    bool solve(string s1, string s2, unordered_map<string, bool>& mp) {
        if (s1 == s2)
            return true;
        int n = s1.size();
        if (n <= 1)
            return false;
        string key = s1 + " " + s2;
        if (mp.find(key) != mp.end())
            return mp[key];
        
        for (int i = 1; i < n; i++) {
            string t1 = s1.substr(0, i);
            string t2 = s2.substr(n - i, i);

            string t3 = s1.substr(i, n - i);
            string t4 = s2.substr(0, n - i);

            if (solve(t1, t2, mp) && solve(t3, t4, mp))
                return mp[key] = true;

            t1 = s1.substr(0, i);
            t2 = s2.substr(0, i);

            t3 = s1.substr(i, n - i);
            t4 = s2.substr(i, n - i);

            if (solve(t1, t2, mp) && solve(t3, t4, mp))
                return mp[key] = true;
        }
        return mp[key] = false;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        for (int x : freq) {
            if (x != 0)
                return false;
        }
        unordered_map<string, bool> mp;
        return solve(s1, s2, mp);
    }
};