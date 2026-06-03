class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        unordered_map<char,char>mp;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])){
                if(t[i]!=mp[s[i]]) return false;
            }
            mp[s[i]]=t[i];
        }

        mp.clear();

        for(int i=0;i<n;i++){
            if(mp.count(t[i])){
                if(s[i]!=mp[t[i]]) return false;
            }
            mp[t[i]]=s[i];
        }

        return true;
    }
};