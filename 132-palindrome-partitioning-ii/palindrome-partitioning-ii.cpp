class Solution {
public:
    vector<vector<int>>ispal;
    int n;
    void check(int mid,string &s){
        //odd length;
        int i=mid;
        int j=mid;
        while(i>=0 && j<n && s[i]==s[j]){
            ispal[i][j]=1;
            i--;
            j++;
        }

        //even length;
        i=mid-1;
        j=mid;
        while(i>=0 && j<n && s[i]==s[j]){
            ispal[i][j]=1;
            i--;
            j++;
        }
    }

    vector<int>dp;

    int f(int idx,string &s){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=INT_MAX;
        for(int i=idx;i<n;i++){
            if(ispal[idx][i]){
                ans=min(ans,1+f(i+1,s));
            }
        }
        return dp[idx]= ans;
    }

    int minCut(string s) {
        n=s.size();
        ispal.assign(n,vector<int>(n,0));
        dp.assign(n,-1);
        for(int i=0;i<n;i++){
            check(i,s);
        }
        return f(0,s)-1;
    }
};