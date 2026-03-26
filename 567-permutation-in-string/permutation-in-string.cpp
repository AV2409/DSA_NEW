
class Solution {
public:
    bool check(vector<int>& need, vector<int>& have) {
        for (int i = 0; i < 26; i++) {
            if (need[i] < have[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) 
    {
        vector<int> need(26);
        vector<int> have(26);
        if (s1.size() > s2.size())
            return false;
        for (char c : s1)
            need[c - 'a']++;
        int k = s1.size();

        for (int i = 0; i < k; i++) {
            have[s2[i] - 'a']++;
        }
        int idx = 0;
        if (check(need, have))
            return true;

        int j = k;
        int n = s2.size();
        while (j < n) {
            have[s2[j] - 'a']++;
            have[s2[idx] - 'a']--;
            idx++;
            if (check(need, have))
                return true;
            j++;
        }
        return false;
    }
};