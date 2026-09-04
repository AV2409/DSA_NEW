class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
        int n = s.size();
        int i=n-1;
        int ans=0;
        while(i>=0){
            ans+=mp[s[i]];
            if(s[i]=='V'||s[i]=='X'){
                if(i-1>=0 && s[i-1]=='I') {
                    ans-=1;
                    i--;
                }
            }
            else if(s[i]=='L'||s[i]=='C'){
                if(i-1>=0 && s[i-1]=='X') {
                    ans-=10;
                    i--;
                }
            }
            else if(s[i]=='D'||s[i]=='M'){
                if(i-1>=0 && s[i-1]=='C') {
                    ans-=100;
                    i--;
                }
            }
            i--;
        }
        return ans;
    }
};