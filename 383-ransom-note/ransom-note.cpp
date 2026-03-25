class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>h1(26);
        // vector<int>h2(26);

        for(char c:magazine){
            h1[c-'a']++;
        }

        for(char c:ransomNote){
            if(h1[c-'a']==0) return false;
            h1[c-'a']--;
        }
        return true;

    }
};