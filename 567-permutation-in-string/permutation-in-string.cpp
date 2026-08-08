class Solution {
public:
    bool check(vector<int>&hash1,vector<int>&hash2){
        for(int i=0;i<26;i++){
            if(hash2[i]<hash1[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2) return false;
        for(char c:s1){
            hash1[c-'a']++;
        }
        int l=0;
        for(int i=0;i<n1;i++){
            hash2[s2[i]-'a']++;
        }
        if(check(hash1,hash2)) return true;
        int r=n1;
        while(r<n2){
            hash2[s2[r]-'a']++;
            hash2[s2[l]-'a']--;
            l++;
            r++;
            if(check(hash1,hash2)) return true;
        }
        return false;

    }
};