class Solution {
public:
    bool check(string& a, string& b) {
        int cnt=0;
        int n1=a.size();
        int n2=b.size();

        if(n1+1!=n2) return false;
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                j++;
                cnt++;
            }
            if(cnt>1) return false;
        }
        return cnt<=1;
    }
    static bool comp(string& a, string& b) { return a.size() < b.size(); }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int lis = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            lis = max(lis, dp[i]);
        }
        return lis;
    }
};