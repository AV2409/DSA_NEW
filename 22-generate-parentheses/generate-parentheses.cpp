class Solution {
public:

    void helper(int op,int cl,int n,string &str,vector<string>&ans){
        if(op==n && cl==n){
            ans.push_back(str);
            return;
        }
        if (op < n) {
            str+='(';
            helper(op + 1, cl, n, str, ans);
            str.pop_back();
        }

        if (cl < op) {
            str+=')';
            helper(op, cl + 1, n, str, ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int op=0;
        int cl=0;

        string str="";
        vector<string>ans;
        helper(op,cl,n,str,ans);
        return ans;
    }
};