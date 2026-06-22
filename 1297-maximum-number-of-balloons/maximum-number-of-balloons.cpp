class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>hash(26);
        for(char c:text){
            hash[c-'a']++;
        }

        int dbl=min(hash['o'-'a'],hash['l'-'a']);
        int single=min({hash['b'-'a'],hash['a'-'a'],hash['n'-'a']});
        dbl=dbl/2;
        int ans=min(dbl,single);

        return ans;
    }
};