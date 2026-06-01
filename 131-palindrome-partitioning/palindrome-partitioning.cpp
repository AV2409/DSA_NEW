class Solution {
public:
    vector<string>lst;
    vector<vector<string>>ans;


    bool isPossible(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string s,int i){
        if(i==s.size()){
            ans.push_back(lst);
            return;
        }
        for(int idx=i;idx<s.size();idx++){
            if(isPossible(s,i,idx)){
                lst.push_back(s.substr(i, idx - i + 1));
                solve(s,idx+1);
                lst.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s,0);
        return ans;
    }
};