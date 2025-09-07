class Solution {
public:
    int minOperations(string s) {
        vector<bool>hash(26);
        int cnt=0;
        for(char i:s){
            if(hash[i-'a']==false){
                hash[i-'a']=true;
                cnt++;
            }
        }
        int ans=0;
        bool onlyA=true;
        for(int i=1;i<26;i++){
            if(hash[i]) {
                ans++;
                hash[(i+1)%26]=true;
                onlyA=false;
            }
        }
        if(onlyA) return 0;
        return ans;
    }
};