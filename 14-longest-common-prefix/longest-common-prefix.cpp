class Solution {
public:
    string find(string& w1, string& w2) {
        string ans;
        int n1 = w1.size();
        int n2 = w2.size();

        int i = 0;
        int j = 0;
        while (i < n1 && j < n2 && w1[i] == w2[j]) {
            ans += w1[i];
            i++;
            j++;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        int mini = 1e9;
        for (int i = 0; i < n; i++) {
            mini = min(mini, (int)strs[i].size());
        }
        for (int i = 0; i < mini; i++) {
            char ch = strs[0][i];
            for (int j = 0; j < n; j++) {
                if(strs[j][i]!=ch) return ans;
            }
            ans+=ch;
        }
        return ans;
    }
};