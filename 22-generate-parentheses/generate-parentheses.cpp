class Solution {
public:
    string s;
    vector<string>ans;
    void helper(int op,int cl){
        if(op==0 && cl==0){
            ans.push_back(s);
            return;
        }

        if(op>=cl){
            s+='(';
            helper(op-1,cl);
            s.pop_back();
        }
        else{
            s+=')';
            helper(op,cl-1);
            s.pop_back();

            if(op>0){
                s+='(';
                helper(op-1,cl);
                s.pop_back();
            }
        }
        
    }
    vector<string> generateParenthesis(int n) {
        helper(n,n);
        return ans;
    }
};