class Solution {
public:
    int n;
    int cnt=0;
    void expand(int i,int j,string &s){
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
            cnt++;
        }
    }
    int countSubstrings(string s) {
        n=s.size();
        for(int i=0;i<n;i++){
            expand(i,i,s);
            expand(i,i+1,s);
        }
        
        return cnt;
    }
};