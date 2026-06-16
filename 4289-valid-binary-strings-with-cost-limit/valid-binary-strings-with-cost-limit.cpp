class Solution {
public:
    void f(int n, int k, string& str, vector<string>& ans, int idx, int cost) {
        if (cost > k)
            return;
        if (str.size() > n)
            return;
        if (str.size() == n) {
            ans.push_back(str);
            return;
        }

        str += '0';
        f(n, k, str, ans, idx + 1, cost);
        str.pop_back();

        if (idx==0) {
            str += "1";
            f(n, k, str, ans, idx + 1, cost + idx);
            str.pop_back();
        }
        else if(str.back()!='1'){
            str += "1";
            f(n, k, str, ans, idx + 1, cost + idx);
            str.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string str = "";
        vector<string> ans;
        f(n, k, str, ans, 0, 0);
        return ans;
    }
};

// class Solution {
// public:
//     void f(int n,int k,string &str,vector<string>&ans,int idx,int cost){
//         if(cost>k) return;
//         if(idx==n-1) {
//             ans.push_back(str);
//             return;
//         }

//         str[idx]='0';
//         f(n,k,str,ans,idx+1,cost);
//         str.pop_back();

//         str+='1';
//         f(n,k,str,ans,idx+1,cost+idx);
//         str.pop_back();

//     }
//     vector<string> generateValidStrings(int n, int k) {
//         string str="";
//         for(int i=0;i<n;i++) str+='0';
//         vector<string>ans;
//         f(n,k,str,ans,0,0);
//         return ans;
//     }
// };