class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mini=201;
        for(string s:strs){
            int x=s.size();
            mini=min(mini,x);
        }

        string ans="";
        int n=strs.size();
        for(int i=0;i<mini;i++){
            char ch=strs[0][i];
            for(int j=1;j<n;j++){
                if(ch!=strs[j][i]) return ans;
            }
            ans+=ch;
        }
        return ans;
    }
};