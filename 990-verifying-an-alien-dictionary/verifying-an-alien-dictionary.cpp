class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>hash(26);
        for(int i=0;i<26;i++){
            char c=order[i];
            hash[c-'a']=i;
        }

        for(int i=0;i<words.size()-1;i++){
            string word1=words[i];
            string word2=words[i+1];

            int n1=word1.size();
            int n2=word2.size();

            int mini=min(n1,n2);
            bool flag=true;
            for(int x=0;x<mini;x++){
                char c1=word1[x];
                char c2=word2[x];
                if(c1!=c2) {
                    flag=false;
                    if(hash[c1-'a']>hash[c2-'a']) return false;
                    break;
                }
            }
            if(flag && n1>n2) return false;
        }
        return true;
    }
};