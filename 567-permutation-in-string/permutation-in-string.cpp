class Solution {
private: 
    bool check(int h1[],int h2[]){
        for(int i=0;i<26;i++){
            if(h1[i]!=h2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();

        if(n1>n2) return false;
        int h1[26]={0};
        int h2[26]={0};
        int index1;
        int index2;

        for(int i=0;i<n1;i++){
            index1=s1[i]-'a';
            h1[index1]++;
        }

        for(int i=0;i<n1;i++){
            index2=s2[i]-'a';
            h2[index2]++;
        }
        if(check(h1,h2)) return true;

        int i=0,j=n1-1;
        
        while(i<n2-n1){
            
            j++;
            h2[s2[j]-'a']++;
            h2[s2[i]-'a']--;
            i++;
            if(check(h1,h2)) return true;
            
            
        }
        return false;


    }
};