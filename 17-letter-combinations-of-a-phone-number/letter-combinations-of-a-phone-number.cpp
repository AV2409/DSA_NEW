class Solution {
public:
    void f(int i, string digits, string& s, vector<string>& ans, int n,unordered_map<char, string> &mp) {
        if (i == n) {
            ans.push_back(s);
            return;
        }

        char ch = digits[i];

        for (int x = 0; x < mp[ch].size(); x++) {
            char cc = mp[ch][x];
            s += cc;
            f(i + 1, digits, s, ans, n,mp);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        
        vector<string>ans;
        string s="";
        f(0,digits,s,ans,n,mp);
        return ans;
    }
};