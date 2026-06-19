class Solution {
public:
    int minFlips(string s) {
        int o=0;
        int z=0;
        int n=s.size();
        if(n<=2) return 0;
        for(char c:s){
            if(c=='0') z++;
            if(c=='1') o++;
        }
        
        if(o<=1) return 0;
        if(o==2){
            if(s[0]=='1' && s[n-1]=='1') return 0;
        }
        if(s[0]=='1' && s[n-1]=='1') return min(z,o-2);
        return min(z,o-1);
    }
};