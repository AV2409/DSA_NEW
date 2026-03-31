class Solution {
public:
    bool valid(vector<int>&have,vector<int>&needed){
        for(int i=0;i<26;i++){
            if(needed[i]!=have[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;

        vector<int>needed(26);
        vector<int>have(26);

        for(char c:s1){
            needed[c-'a']++;
        }

        int l=0;
        int r=0;
        while(r<n1){
            have[s2[r]-'a']++;
            r++;
        }
        if(valid(have,needed)) return true;
        while(r<n2){
            have[s2[r]-'a']++;
            r++;
            have[s2[l]-'a']--;
            l++;
            if(valid(have,needed)) return true;
        }
        return false;
    }
};