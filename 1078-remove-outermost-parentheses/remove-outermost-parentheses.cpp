class Solution {
public:
    string removeOuterParentheses(string s) {
        int op = 0;
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if(op>0) ans+=s[i];
                op++;
            }
            if (s[i] == ')'){
                op--;
                if(op>0) ans+=s[i];
            }   
        }
        return ans;
    }
};