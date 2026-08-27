class Solution {
public:
    vector<int> hash;
    string ans = "";
    int n;

    bool find(int i, string& target) {
        if (i == n)
            return true;
        int ch = target[i] - 'a';
        bool equal=true;
        if(i==n-1) equal=false;
        for (int j = 0; j < 26; j++) {
            if(j<ch) continue;
            if (j == ch && hash[j] && equal) {
                hash[j]--;
                ans += j + 'a';
                if (find(i + 1, target)) {
                    return true;
                }
                ans.pop_back();
                hash[j]++;
            } 
            else if (j > ch && hash[j]) {
                hash[j]--;
                ans += j + 'a';
                for (int k = 0; k < 26; k++) {
                    for (int x = 0; x < hash[k]; x++) {
                        ans += k + 'a';
                    }
                }
                return true;
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        sort(s.begin(), s.end());
        string smallest = s;
        reverse(s.begin(), s.end());
        string largest = s;

        if (target >= largest)
            return "";
        if (target < smallest)
            return smallest;

        hash.assign(26,0);
        for (char c : s) {
            hash[c - 'a']++;
        }

        n = s.size();

        if(find(0,target)) return ans;
        return "";
    }
};