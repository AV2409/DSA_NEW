class Solution {
public:
    string find(string& word,unordered_set<string>&st,int maxi){
        int z=word.size();
        int ss=min(maxi,z);
        string temp="";
        for(int i=0;i<ss;i++){
            temp+=word[i];
            if(st.count(temp)) return temp;
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        int maxi=0;
        unordered_set<string>st;
        for(string w:dictionary){
            st.insert(w);
            maxi=max(maxi,(int)w.size());
        }

        vector<string>words;
        int n=sentence.size();
        for(int i=0;i<n;i++){
            string temp="";
            while(i<n && sentence[i]!=' '){
                temp+=sentence[i];
                i++;
            }
            words.push_back(temp);
        }
        
        string ans;
        for(string word:words){
            string x=find(word,st,maxi);
            ans+=x;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};