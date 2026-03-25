class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>hash(26);
        for(char c:text){
            hash[c-'a']++;
            // if(c=='b'||c=='a'||c=='n'){
            //     ans=min(ans,hash[c-'a']);
            // }
            // if(c=='l'||c=='o'){
            //     ans=min(ans,hash[c-'a']/2);
            // }
        }

        int dbl=min(hash['o'-'a'],hash['l'-'a']);
        int single=min({hash['b'-'a'],hash['a'-'a'],hash['n'-'a']});
        dbl=dbl/2;
        int ans=min(dbl,single);

        return ans;
    }
};