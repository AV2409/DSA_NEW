class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,0);
        int n = s.size();

        int l = 0;
        int dup = 0;
        int ans=0;
        for (int r = 0; r < n; r++) {
            hash[s[r]]++;
            if (hash[s[r]] == 2)
                dup++;
            while (dup > 0) {
                hash[s[l]]--;
                if (hash[s[l]] == 1)
                    dup--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};