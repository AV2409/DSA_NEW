class Solution {
public:
    string removeDuplicates(string s) {
        string temp;

        for(int i=0;i<s.length();i++){
            if(temp.length()==0||temp.back()!=s[i]) temp.push_back(s[i]);
            else temp.pop_back();
        }
        return temp;
        
    }
};