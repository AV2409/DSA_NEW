class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.size();
        int ans = 0;
        vector<int> hash(3);
        int i=0;
        for (int j = i; j < n; j++) {
            hash[s[j] - 'a']++;
            while (hash[0] && hash[1] && hash[2]) {
                ans += n - j;
                hash[s[i]-'a']--;
                i++;
            }
        }

        return ans;
    }
};