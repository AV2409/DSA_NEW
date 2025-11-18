class Solution {
public:
    int numSub(string s) {
        long long res = 0;
        const long long MOD = 1000000007;
        
        int i = 0;
        int n = s.size();
        vector<long long> zz;

        while(i < n){
            if(s[i] == '0') {
                i++;
            } else {
                int j = i;
                while(i < n && s[i] == '1') i++;
                zz.push_back(i - j);
            }
        }

        for(long long x : zz){
            long long temp = ((x % MOD) * ((x + 1) % MOD) / 2) % MOD;
            res = (res + temp) % MOD;
        }

        return (int)res;
    }
};
