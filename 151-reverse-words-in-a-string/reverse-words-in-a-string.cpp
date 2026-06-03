class Solution {
public:
    
    string reverseWords(string s) {
        string temp="";
        vector<string>ans;
        for(char c:s){
            if(c==' '){
                if(temp!="") ans.push_back(temp);
                temp="";
            }
            else{
                temp+=c;
            }
        }
        if(temp!="") ans.push_back(temp);

        reverse(ans.begin(),ans.end());
        string res;
        for(string str:ans){
            res+=str;
            res+=' ';
        }
        res.pop_back();
        return res;
    }
};