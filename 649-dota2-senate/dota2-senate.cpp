class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        vector<int> skipped(n, 0);

        int r = 0;
        int d = 0;
        int rskip = 0;
        int dskip = 0;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                r++;
            else
                d++;
        }

        while (r > 0 && d > 0) {

            for (int i = 0; i < n; i++) {
                if (skipped[i])
                    continue;
                if (senate[i] == 'R') {
                    if (rskip) {
                        skipped[i] = 1;
                        rskip--;
                    } else {
                        d--;
                        dskip++;
                        if (d <= 0)
                            return "Radiant";
                    }

                }

                else if (senate[i] == 'D') {
                    if (dskip) {
                        skipped[i] = 1;
                        dskip--;
                    } else {
                        r--;
                        rskip++;
                        if (r <= 0)
                            return "Dire";
                    }
                }
            }
        }
        if(d>0) return "Dire";

        return "Radiant";
    }
};