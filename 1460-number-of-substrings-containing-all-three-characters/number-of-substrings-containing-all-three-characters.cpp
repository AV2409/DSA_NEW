class Solution {
public:
    int atmost(string &s,int k){
        int n = s.size();
        int ans = 0;
        vector<int> hash(3);
        int i=0;
        int cnt=0;
        for (int j = 0; j < n; j++) {
            if(hash[s[j]-'a']==0) cnt++;
            hash[s[j] - 'a']++;
            while (cnt>k) {
                hash[s[i]-'a']--;
                if(hash[s[i]-'a']==0) cnt--;
                i++;
            }
            ans += j-i+1;
        }

        return ans;
    }
    int numberOfSubstrings(string s) {
        return atmost(s,3)-atmost(s,2);
    }
};