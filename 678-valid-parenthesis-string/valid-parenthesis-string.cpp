class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int op=0;
        int ss=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') op++;
            else if(s[i]=='*') ss++;

            else{
                if(op==0&&ss==0) return false;
                if(op) op--;
                else{
                    ss--;
                }
            }
        }
        int cl=0;
        ss=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]==')') cl++;
            else if(s[i]=='*') ss++;

            else{
                if(cl==0&&ss==0) return false;
                if(cl) cl--;
                else{
                    ss--;
                }
            }
        }

        return true;
    }
};