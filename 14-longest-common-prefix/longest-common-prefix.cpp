class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();

        int minLen=210;
        for(string x:strs){
            int ss=x.size();
            minLen=min(minLen,ss);
        }

        for(int i=0;i<minLen;i++){
            char ch=strs[0][i];
            for(int j=0;j<n;j++){
                if(strs[j][i]!=ch) return ans;
            }
            ans+=ch;
        }
        return ans;
    }
};