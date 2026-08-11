class Solution {
public:
    vector<vector<bool>>isPal;
    int n;
    int cnt=0;
    void expand(int i,int j,string &s){
        while(i>=0 && j<n && s[i]==s[j]){
            isPal[i][j]=true;
            i--;
            j++;
            cnt++;
        }
    }
    int countSubstrings(string s) {
        n=s.size();
        isPal.assign(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            expand(i,i,s);
            expand(i,i+1,s);
        }
        
        return cnt;
    }
};