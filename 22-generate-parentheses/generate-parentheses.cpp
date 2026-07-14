class Solution {
public:
    string s;
    vector<string>ans;

    void f(int open,int closed){
        if(open==0&&closed==0){
            ans.push_back(s);
            return;
        }

        if(closed==0) return;

        if(open>=closed){
            s+='(';
            f(open-1,closed);
            s.pop_back();
        }

        else{
            if(open){
                s+='(';
                f(open-1,closed);
                s.pop_back();
            }
            s+=')';
            f(open,closed-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        f(n,n);
        return ans;
    }
};