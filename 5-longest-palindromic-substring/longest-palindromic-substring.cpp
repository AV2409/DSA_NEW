class Solution {
public:
    vector<vector<int>> ispal;
    int n;
    void check(int mid, string& s) {
        // odd length;
        int i = mid;
        int j = mid;
        while (i >= 0 && j < n && s[i] == s[j]) {
            ispal[i][j] = 1;
            i--;
            j++;
        }

        // even length;
        i = mid - 1;
        j = mid;
        while (i >= 0 && j < n && s[i] == s[j]) {
            ispal[i][j] = 1;
            i--;
            j++;
        }
    }
    string longestPalindrome(string s) {
        n = s.size();
        int start = 0;
        int maxLen = 1;

        ispal.assign(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            check(i,s);
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispal[i][j]) {
                    int len=j-i+1;
                    if(len>maxLen){
                        maxLen=len;
                        start=i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};