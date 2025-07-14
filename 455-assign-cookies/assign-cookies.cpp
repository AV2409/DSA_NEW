class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gs = g.size();
        int ss = s.size();
        int i=0;
        int j=0;
        int cnt = 0;
        while (i < gs && j < ss) {
            if (s[j] >= g[i]) {
                cnt++;
                j++;
                i++;
            } else {
                j++;
            }
        }
        return cnt;
    }
};