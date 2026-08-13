class Solution {
public:
    bool checkValidString(string s) {
        int op=0;
        int cl=0;

        int n=s.size();
        deque<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') op++;
            else if(s[i]=='*') st.push_back(i);
            else{
                if(op) op--;
                else if(!st.empty()) {
                    st.pop_front();
                }
                else return false;
            } 
        }

        for(int i=n-1;i>=0;i--){
            if(s[i]==')') cl++;
            else if(s[i]=='*') continue;
            else{
                if(cl) cl--;
                else if(!st.empty()){
                    int idx=st.back();
                    st.pop_back();
                    if(idx<i) return false;
                }
                else return false;
            } 
        }
        return true;

    }
};