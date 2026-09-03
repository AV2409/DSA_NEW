class Solution {
public:
    bool check(vector<int>&needed,vector<int>&have){
        for(int i=0;i<26;i++){
            if(have[i]!=needed[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>needed(26);
        vector<int>have(26);
        int n1=s.size();
        int n2=p.size();
        if(n2>n1) return {};

        for(int i=0;i<n2;i++){
            needed[p[i]-'a']++;
        }

        for(int i=0;i<n2;i++){
            have[s[i]-'a']++;
        }
        vector<int>ans;

        if(check(have,needed)) ans.push_back(0);
        for(int i=n2;i<n1;i++){
            have[s[i]-'a']++;
            have[s[i-n2]-'a']--;
            if(check(have,needed)){
                ans.push_back(i-n2+1);
            }
        }
        return ans;
    }
};