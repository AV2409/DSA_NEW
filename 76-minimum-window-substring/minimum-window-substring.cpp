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

        for(int r=0;r<n1;r++){
            have[s[r]]++;
            while(valid(have,needed)){
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                have[s[l]]--;
                l++;
            }
        }

        if(minLen==1e9) return ans;
        string res = s.substr(start, minLen); 
        return res;
    }
};