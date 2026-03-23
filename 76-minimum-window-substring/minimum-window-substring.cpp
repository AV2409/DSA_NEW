class Solution {
public:

    bool valid(vector<int>have,vector<int>needed){
        for(int i=0;i<255;i++){
            if(have[i]<needed[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n1=s.size();
        int n2=t.size();

        vector<int>needed(256);
        vector<int>have(256);
        int len=1e9;
        int start=-1;
        for(char c:t){
            needed[c]++;
        }
        int l=0;
        for(int r=0;r<n1;r++){
            have[s[r]]++;

            while(valid(have,needed)){

                if(len>r-l+1){
                    len=min(len,r-l+1);
                    start=l;
                }
                have[s[l]]--;
                l++;
            }
        }

        if(len==1e9) return "";
        string ans=s.substr(start,len);
        return ans;
    }
};