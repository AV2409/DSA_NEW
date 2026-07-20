class Solution {
public:
    string removeOccurrences(string s, string part) {
        int x = part.length();
        int ss=s.size();
        if (s.length() < part.length())
            return s;
        while (true) {
            int n = s.find(part);
            if(n==string::npos) break;
            s.erase(n, x);
        }

        return s;
    }
};