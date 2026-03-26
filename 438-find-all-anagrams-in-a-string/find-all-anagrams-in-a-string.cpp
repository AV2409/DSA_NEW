class Solution {
public:
    bool check(vector<int>&need,vector<int>&have){
        for(int i=0;i<26;i++){
            if(need[i]<have[i]) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>need(26);
        vector<int>have(26);
        if(p.size() > s.size()) return {};
        for(char c:p) need[c-'a']++;
        int k=p.size();

        for(int i=0;i<k;i++){
            have[s[i]-'a']++;
        }
        int idx=0;
        vector<int>ans;
        if(check(need,have)) ans.push_back(0);

        int j=k;
        int n=s.size();
        while(j<n){
            have[s[j]-'a']++;
            have[s[idx]-'a']--;
            idx++;
            if(check(need,have)) ans.push_back(idx);
            j++;
        }
        return ans;
    }
};