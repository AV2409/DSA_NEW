class Solution {
public:
    bool check(vector<int>&needed,vector<int>&have){
        for(int i=0;i<256;i++){
            if(needed[i]>have[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int>have(256,0);
        vector<int>needed(256,0);
        vector<int>hash(256,0);
        int cnt1=0;
        for(char c:t){
            if(hash[c]++==0) cnt1++;
            needed[c]++;
        }

        int n=s.size();
        int st=-1;
        int len=1e9;
        int l=0;
        int cnt2=0;
        for(int r=0;r<n;r++){
            char ch=s[r];
            if(--hash[ch]==0) cnt2++;
            have[ch]++;
            while(cnt1==cnt2){
                if(r-l+1<len){
                    len=r-l+1;
                    st=l;
                }
                if(++hash[s[l]]==1) cnt2--;
                have[s[l]]--;
                l++;
            }
        }
        if(st==-1) return "";
        return s.substr(st,len);
    }
};