class Solution {
public:
    void f(int k, int n,int i,vector<int>&list,vector<vector<int>>&ans){
        if(k==0 && n==0){
            ans.push_back(list);
            return;
        }
        if(k==0||n==0||i==10) return;
        
        f(k,n,i+1,list,ans);

        list.push_back(i);
        f(k-1,n-i,i+1,list,ans);
        list.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>list;
        vector<vector<int>>ans;
        f(k,n,1,list,ans);
        return ans;
    }
};