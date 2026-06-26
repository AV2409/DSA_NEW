class Solution {
public:
    string lst;
    vector<string> ans;
    void solve(string& s, int idx, int comp) {
        if (idx == s.size()) {
            if (comp == 4) {
                string temp = lst;
                temp.pop_back();
                ans.push_back(temp);
            }

            return;
        }
        for(int i=idx;i<min(idx+3,(int)s.size());i++) {
            string str = s.substr(idx, i - idx + 1);
            long long x = stoll(str);
            if (s[idx] == '0' && i > idx)
                break;
            if (x >= 0 && x <= 255) {
                int len = lst.size();
                lst += str;
                lst += '.';
                solve(s, i + 1, comp + 1);
                lst.resize(len);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0);
        return ans;
    }
};