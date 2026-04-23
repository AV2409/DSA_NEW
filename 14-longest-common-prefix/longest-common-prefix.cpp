class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        int mini=201;
        for(int i=0;i<n;i++){
            int x=strs[i].size();
            mini=min(mini,x);
        }

        for(int i=0;i<mini;i++){
            char ch=strs[0][i];
            for(int j=1;j<n;j++){
                string word=strs[j];
                if(word[i]!=ch) return ans;
            }
            ans+=ch;
        }
        return ans;
    }
};