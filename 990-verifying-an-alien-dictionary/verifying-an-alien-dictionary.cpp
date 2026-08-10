class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>hash(26);
        for(int i=0;i<26;i++){
            hash[order[i]-'a']=i;
        }

        int n=words.size();
        for(int i=0;i<n-1;i++){
            string w1=words[i];
            string w2=words[i+1];

            int n1=w1.size();
            int n2=w2.size();
            int x=0;
            int y=0;
            while(x<n1 && y<n2){
                if(w1[x]==w2[y]){
                    x++;
                    y++;
                }
                else break;
            }
            if(y==n2 && x!=n1) return false;
            if(x!=n1){
                int ord1=hash[w1[x]-'a'];
                int ord2=hash[w2[y]-'a'];
                if(ord1>ord2) return false;
            }
        }
        return true;
    }
};