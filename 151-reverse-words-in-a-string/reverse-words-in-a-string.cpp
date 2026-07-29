class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        vector<string> str;
        string x = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (!x.empty()) {
                    str.push_back(x);
                    x = "";
                }
                continue;
            }
            x += s[i];
        }
        if (!x.empty()) {
            str.push_back(x);
        }
        int ss=str.size();
        for(int i=ss-1;i>=0;i--){
            ans+=str[i];
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};