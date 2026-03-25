class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        bool val = false;
        int ans = 0;

        for (auto it : mp) {
            if (it.second % 2 == 0)
                ans += it.second;
            else {
                ans+=it.second-1;
                val=true;
            }
        }

        if(val) return ans + 1;
        return ans;
    }
};