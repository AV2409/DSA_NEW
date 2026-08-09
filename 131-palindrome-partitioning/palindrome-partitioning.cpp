class Solution {
public:
    vector<vector<int>>ispal;
    int n;
    void expand(int i,int j,string &s){
        while(i>=0 && j<n){
            if(s[i]==s[j]){
                ispal[i][j]=1;
                i--;
                j++;
            }
            else break;
        }
    }
    vector<vector<string>>ans;
    vector<string>list;
    void f(int i,string &s){
        if(i==n){
            ans.push_back(list);
            return;
        }

        for(int part=i;part<n;part++){
            if(ispal[i][part]){
                string temp=s.substr(i,part-i+1);
                list.push_back(temp);
                f(part+1,s);
                list.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.size();
        ispal.assign(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            //odd
            expand(i,i,s);
            //even
            expand(i,i+1,s);
        }
        f(0,s);
        return ans;

    }
};