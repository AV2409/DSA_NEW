class Solution {
public:

    bool valid(vector<int>&have,vector<int>&needed){
        for(int i=0;i<256;i++){
            if(needed[i]>have[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n1=s.size();
        int n2=t.size();

        string ans="";
        if(n2>n1) return ans;
        int start=0;
        int minLen=1e9;

        int l=0;
        int r=0;
        vector<int>needed(256);
        vector<int>have(256);

        for(char c:t){
            needed[c]++;
        }
        int cnt=t.size();

        for(int r=0;r<n1;r++){
            if (needed[s[r]] > 0) {
                have[s[r]]++;
                if (have[s[r]] <= needed[s[r]]) {
                    cnt--;
                }
            }
            while(cnt==0){
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                if (needed[s[l]] > 0) {
                    have[s[l]]--;
                    if (have[s[l]] < needed[s[l]]) {
                        cnt++;
                    }
                }
                l++;
            }
        }

        if(minLen==1e9) return ans;
        string res = s.substr(start, minLen); 
        return res;
    }
};