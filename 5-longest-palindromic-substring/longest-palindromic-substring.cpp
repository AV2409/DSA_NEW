class Solution {
public:
    vector<vector<bool>>isPal;
    int n;
    void expand(int i,int j,string &s){
        while(i>=0 && j<n && s[i]==s[j]){
            isPal[i][j]=true;
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        n=s.size();
        isPal.assign(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            expand(i,i,s);
            expand(i,i+1,s);
        }

        int st=0;
        int len=1;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal[i][j]){
                    if(j-i+1>len){
                        len=j-i+1;
                        st=i;
                    }
                }
            }
        }

        return s.substr(st,len);

    }
};