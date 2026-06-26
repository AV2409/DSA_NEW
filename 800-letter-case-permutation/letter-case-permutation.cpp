class Solution {
public:
    void solve(int idx,string &s,string list,vector<string>& ans){
        if(idx==s.size()){
            ans.push_back(list);
            return;
        }

        if(s[idx]>='0' &&s[idx]<='9'){
            list+=s[idx];
            solve(idx+1,s,list,ans);
            return;
        }

        char chL='a';
        char chU='A';
        int offset=0;
        if(s[idx]>='a' &&s[idx]<='z'){
            offset=s[idx]-'a';
        }
        if(s[idx]>='A' &&s[idx]<='Z'){
            offset=s[idx]-'A';
        }

        chL+=offset;
        chU+=offset;
        
        list+=chL;
        solve(idx+1,s,list,ans);
        list.pop_back();

        list+=chU;
        solve(idx+1,s,list,ans);
        list.pop_back();
    }
    vector<string> letterCasePermutation(string s) {
        string list;
        vector<string> ans;
        solve(0,s,list,ans);
        return ans;
    }
};