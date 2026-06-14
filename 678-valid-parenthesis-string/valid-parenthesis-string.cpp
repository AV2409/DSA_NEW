class Solution {
public:
    bool checkValidString(string s) {
        int mini=0;
        int maxi=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }

            else if(s[i]==')'){
                mini--;
                maxi--;
            }

            else{
                mini--;
                maxi++;
            }

            if(maxi < 0)
                return false;

            mini = max(mini, 0);
        }
        return mini==0;
    }
};