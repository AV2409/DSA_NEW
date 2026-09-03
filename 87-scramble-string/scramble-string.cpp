class Solution {
public:
    unordered_map<string,bool>dp;
    bool f(string s1, string s2){
        if(s1.size()==1 && s2.size()==1) return s1==s2;

        string id=s1+"-"+s2;
        if(dp.count(id)) return dp[id];
        int n=s1.size();
        for(int len=1;len<n;len++){
            int len2=n-len;
            //no swap
            string a1=s1.substr(0,len);
            string a2=s1.substr(len,len2);
            string b1=s2.substr(0,len);
            string b2=s2.substr(len,len2);

            if(f(a1,b1) && f(a2,b2)) return dp[id] = true;


            string b3=s2.substr(0,len2);
            string b4=s2.substr(len2,len);

            if(f(a1,b4) && f(a2,b3)) return dp[id] = true;
        }
        return dp[id] = false;
    }
    bool isScramble(string s1, string s2) {
        if(s1==s2) return true;
        return f(s1,s2);
    }
};