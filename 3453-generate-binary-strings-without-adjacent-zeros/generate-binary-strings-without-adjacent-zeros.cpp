class Solution {
public:
    void helper(int n,string &str,vector<string> &ans){
        if(str.size()==n){
            ans.push_back(str);
            return;
        }
        char ch=str.back();
        if(ch=='0'){
            str+='1';
            helper(n,str,ans);
            str.pop_back();
        }
        else{
            str+='1';
            helper(n,str,ans);
            str.pop_back();
            str+='0';
            helper(n,str,ans);
            str.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string str1="0";
        string str2="1";

        vector<string>ans;
        helper(n,str1,ans);
        helper(n,str2,ans);
        return ans;
    }
};