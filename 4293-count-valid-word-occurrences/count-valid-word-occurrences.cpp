class Solution {
public:
    bool isA(char& ch) {
        if (ch >= 'a' && ch <= 'z')
            return true;
        return false;
    }
    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {
        unordered_map<string, int> mp;
        string s = "";
        for (string str : chunks) {
            s += str;
        }
        int n = s.size();
        string temp = "";
        for (int i = 0; i < n; i++) {
            while (i < n && !isA(s[i])) {
                i++;
            }
            while (i < n && isA(s[i])) {
                temp += s[i];
                i++;
            }
            if (i == n && temp.size() > 0) {
                cout << temp << endl;
                mp[temp]++;
                temp="";
            } 
            else if (s[i] == '-') {
                bool prev = false;
                bool next = false;
                if (i - 1 >= 0 && isA(s[i - 1]))
                    prev = true;
                if (i + 1 < n && isA(s[i + 1]))
                    next = true;

                if (prev && next)
                    temp += '-';
                // separator
                else {
                    if (temp.size() > 0) {
                        cout << temp << endl;
                        mp[temp]++;
                        temp="";
                    }
                }
            } 
            else if (s[i] == ' ') {
                if (temp.size() > 0) {
                    cout << temp << endl;
                    mp[temp]++;
                    temp="";
                }
            }
        }
        vector<int>ans;

        for(string str:queries){
            ans.push_back(mp[str]);
        }

        return ans;
    }
};