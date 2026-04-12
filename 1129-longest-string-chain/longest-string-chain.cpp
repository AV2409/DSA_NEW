class Solution {
public:
    bool isPred(string& w1, string& w2) {
        if (w2.size() - w1.size() != 1)
            return false;
        
        int n1=w1.size();
        int n2=w2.size();

        int i=0;
        int j=0;
        while(i<n1 &&j<n2){
            if(w1[i]==w2[j]) {
                i++;
                j++;
            }

            else{
                j++;
            }

        }
        return i==n1;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        int n = words.size();
        int ans = 0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPred(words[j],words[i]))
                    dp[i] = max(dp[i], 1 + dp[j]);
            }

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};