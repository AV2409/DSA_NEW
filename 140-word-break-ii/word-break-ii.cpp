class Solution {
public:
    set<string>st;
    vector<string>ans;
    string str;
    int n;
    void helper(int i,string &s){
        if(i==n){
            str.pop_back();
            ans.push_back(str);
            str+=" ";
            return;
        }

        for(int part=i;part<n;part++){
            string temp=s.substr(i,part-i+1);
            if(st.count(temp)){
                str+=temp;
                str+=" ";
                helper(part+1,s);
                str.pop_back();
                int nn=temp.size();
                while(nn--){
                    str.pop_back();
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        st.insert(wordDict.begin(),wordDict.end());
        n=s.size();
        helper(0,s);
        return ans;
    }
};