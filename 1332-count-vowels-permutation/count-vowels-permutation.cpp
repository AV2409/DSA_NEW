class Solution {
public:
    unordered_map<char, vector<char>> mp;
    int N;
    const int MOD=1e9+7;
    unordered_map<int, unordered_map<char,int>> dp;
    int f(int i, char c) { 
        if(i==N) return 1;
        if(dp[i][c]!=0) return dp[i][c];
        int temp=0;
        for(auto ch:mp[c]){
            temp=(temp%MOD+f(i+1,ch)%MOD)%MOD;
        }
        return dp[i][c]= temp%MOD;
     }
    int countVowelPermutation(int n) {
        N=n;
        mp = {{'a', {'e'}},
              {'e', {'a', 'i'}},
              {'i', {'a', 'e', 'o', 'u'}},
              {'o', {'i', 'u'}},
              {'u', {'a'}}};

        int ans=0;
        for(auto it:mp){
            ans=(ans+f(1,it.first))%MOD;
        }

        return ans;
    }
};