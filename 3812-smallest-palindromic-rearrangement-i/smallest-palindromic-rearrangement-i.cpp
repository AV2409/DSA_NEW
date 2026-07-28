class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        int req=n/2;
        sort(s.begin(),s.begin()+req);
        // cout<<req;
        int i=0;
        int j=n-1;
        while(i<req){
            s[j]=s[i];
            // cout<<i<<" "<<j;
            i++;
            j--;
        }
        return s;
    }
};