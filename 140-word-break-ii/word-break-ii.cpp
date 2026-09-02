class Solution {
public:
    
    vector<string>ans;
    vector<string>lst;
    unordered_set<string>st;
    int n;
    void updateAns(){
        string str="";
        for(string x:lst){
            str+=x;
            str+=" ";
        }
        str.pop_back();
        ans.push_back(str);
    }
    void f(int i,string &s){
        if(i==n){
            updateAns();
            return;
        }

        string temp="";
        for(int part=i;part<n;part++){
            temp+=s[part];
            if(st.count(temp)){
                lst.push_back(temp);
                f(part+1,s);
                lst.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st.insert(wordDict.begin(),wordDict.end());
        n=s.size();
        f(0,s);
        return ans;
    }
};