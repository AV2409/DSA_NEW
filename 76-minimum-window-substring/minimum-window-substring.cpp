class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        int cnt1=0;
        vector<int>hash(256,0);
        for(char c:t) {
            if(hash[c]==0) cnt1++;
            hash[c]++;
        }

        int l=0;
        int cnt2=0;
        int st=-1;
        int minlen=INT_MAX;
        for(int r=0;r<m;r++){
            hash[s[r]]--;
            if(hash[s[r]]==0) cnt2++;
            while(cnt1==cnt2){
                int len=r-l+1;
                if(len<minlen){
                    minlen=len;
                    st=l;
                }
                if(hash[s[l]]==0) cnt2--;
                hash[s[l]]++;
                l++;
            }
        }
        if(st==-1) return "";
        return s.substr(st,minlen);
    }
};