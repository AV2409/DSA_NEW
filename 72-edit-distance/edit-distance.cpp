class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,string &w1, string &w2){
        if(i<0 && j<0) return 0;
        if(i<0 || j<0){
            if(i<0) return j+1;
            return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=INT_MAX;
        if(w1[i]==w2[j]){
            ans=min(ans,f(i-1,j-1,w1,w2));
        }
        else{
            //delete
            int op1=1+f(i-1,j,w1,w2);
            //insert
            int op2=1+f(i,j-1,w1,w2);
            //replace
            int op3=1+f(i-1,j-1,w1,w2);

            int mini=min({op1,op2,op3});
            ans=min(ans,mini);
        }

        return dp[i][j]=  ans;
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        dp.assign(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,word1,word2);
    }
};