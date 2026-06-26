class Solution {
public:
    vector<int>vis;
    int cnt;
    int K;
    void f(string& s,string& list,string& ans){
        if(list.size()==s.size()){
            cnt++;
            if(cnt==K){
                ans=list;
            }
            return;
        }
        if(!ans.empty()) return;
        for(int j=0;j<s.size();j++){
            if(!vis[j]){
                list.push_back(s[j]);
                vis[j]=1;
                f(s,list,ans);
                list.pop_back();
                vis[j]=0;
            }
        }
    }
    string getPermutation(int n, int k) {
        string s;
        cnt=0;
        K=k;
        char ch='1';
        for(int i=1;i<=n;i++){
            s+=ch;
            ch++;
        }
        vis.assign(n,0);
        string ans;
        string list;
        f(s,list,ans);
        return ans;
    }
};