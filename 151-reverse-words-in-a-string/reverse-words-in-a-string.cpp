class Solution {
public:
    string reverseWords(string s) {
        vector<string> strs;
        int n = s.size();
        int i = 0;
        string temp = "";
        while (i < n) {
            if (s[i] != ' ') {
                temp += s[i];
                i++;
                continue;
            }

            while (i < n && s[i] == ' ')
                i++;
            if (temp.size()) {
                strs.push_back(temp);
                temp = "";
            }
        }
        if (temp.size()) {
            strs.push_back(temp);
            temp = "";
        }

        int x=strs.size();
        string ans="";
        for(int i=x-1;i>=0;i--){
            ans+=strs[i];
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};