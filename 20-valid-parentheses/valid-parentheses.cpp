class Solution {
public:

    bool isValid(string s) {
        int n=s.size();
        int valid=true;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char c=st.top();
                if(s[i]==')'&&c=='(') st.pop();
                else if(s[i]==']'&&c=='[') st.pop();
                else if(s[i]=='}'&&c=='{') st.pop();
                else break;
            }
        }
        return st.empty();
    }
};