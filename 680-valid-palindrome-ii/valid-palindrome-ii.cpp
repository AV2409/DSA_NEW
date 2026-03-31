class Solution {
public:

    bool check(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;

        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                break;
            }
        }

        if(l>=r) return true;
        bool x1=check(s,l+1,r);
        bool x2=check(s,l,r-1);
        return x1||x2;

    }
};