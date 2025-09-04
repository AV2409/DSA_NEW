class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int cnt=0;
        string res;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt) res+=s[i];
                cnt++;
            }
            else{
                cnt--;
                if(cnt) res+=s[i];
            }
        }
        return res;
    }
};