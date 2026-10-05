class Solution {
public:
    int st=-1;
    int len=0;
    int n;
    void expand(int i,int j,string &s){
        while(i>=0 && j<n && s[i]==s[j]){
            if(j-i+1>len){
                st=i;
                len=j-i+1;
            }
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        n=s.size();
        for(int i=0;i<n;i++){
            expand(i,i,s);
            expand(i,i+1,s);
        }
        return s.substr(st,len);
    }
};