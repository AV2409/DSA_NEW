class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>diff(n);

        for(auto shift:shifts){
            int st=shift[0];
            int end=shift[1];
            int dir=shift[2];
            if(dir==0) dir--;

            diff[st]+=dir;
            if(end+1<n) diff[end+1]-=dir;
        }

        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }

        for(int i=0;i<n;i++){
            int shift=diff[i];
            int curr=s[i]-'a';

            int to = ((curr+shift)%26+26)%26;
            s[i]='a'+to;
        }
        return s;

    }
};