class Solution {
public:
    void helper(int op,int cl,string &str,set<string>&ans){
        if(op<0||cl<0) return;
        if(op==0 && cl==0){
            ans.insert(str);
            return;
        }
        if(op==0){
            str+=')';
            helper(op,cl-1,str,ans);
            str.pop_back();
        }
        if(op>cl) return;
        if(op==cl){
            str+='(';
            helper(op-1,cl,str,ans);
            str.pop_back();
        }
        else{
            str+='(';
            helper(op-1,cl,str,ans);
            str.pop_back();

            str+=')';
            helper(op,cl-1,str,ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int op=n;
        int cl=n;

        string str="";
        set<string>ans;
        helper(op,cl,str,ans);
        vector<string>res;
        for(auto s:ans) res.push_back(s);
        return res;
    }
};