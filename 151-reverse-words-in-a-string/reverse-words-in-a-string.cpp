class Solution {
    bool validchar(char ch){
        if((ch>='A' && ch<='Z')
        ||(ch>='a' && ch<='z')
        ||(ch>='0' && ch<='9'))
        {
            return 1;
        }

        return 0;
    }
public:
    string reverseWords(string s) {
        string ans;

        vector<string> words;

        int i=0,j=0;
        int n=s.length();

        while(i<n){
            while(i<n && validchar(s[i])==0) i++;

            if(i>=n) break;
            j=i;

            while(j<n&&validchar(s[j])==1) j++;

            string temp;
            for(int x=i;x<j;x++){
                temp.push_back(s[x]);
            }
            words.push_back(temp);

            // words.push_back(s.substr(i, j - i));


            i=j+1;
        }
        int k;
        for (int k=words.size()-1;k>0;k--){
            ans+=words[k];
            ans+=" ";
        }

        ans+=words[k];
        return ans;
    }
};