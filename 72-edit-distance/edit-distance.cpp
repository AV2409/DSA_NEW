class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,string &word1, string &word2){
        if(i<0 && j<0) return 0;
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]= f(i-1,j-1,word1,word2);

        int del=1+f(i,j-1,word1,word2);
        int ins=1+f(i-1,j,word1,word2);
        int rep=1+f(i-1,j-1,word1,word2);

        return dp[i][j]= min({del,ins,rep});
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        dp.assign(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,word1,word2);


    }
};