class Solution {
public:
    vector<vector<int>>ispal;
    int n;
    void check(int mid,string &s){
        //odd length;
        int i=mid;
        int j=mid;
        while(i>=0 && j<n && s[i]==s[j]){
            ispal[i][j]=1;
            i--;
            j++;
        }

        //even length;
        i=mid-1;
        j=mid;
        while(i>=0 && j<n && s[i]==s[j]){
            ispal[i][j]=1;
            i--;
            j++;
        }
    }

    int countSubstrings(string s) {
        n=s.size();
        ispal.assign(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            check(i,s);
        }
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ispal[i][j]) ans++;
            }
        }
        return ans;
    }
};