class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        int st = newInterval[0];
        int end = newInterval[1];

        vector<vector<int>> ans;
        bool inserted = false;

        for (auto it : intervals) {
            int s = it[0];
            int e = it[1];

            // Current interval is completely before newInterval
            if (e < st) {
                ans.push_back({s, e});
            }

            // Current interval overlaps newInterval
            else if (s <= end) {
                st = min(st, s);
                end = max(end, e);
            }

            // Current interval is completely after newInterval
            else {
                if (!inserted) {
                    ans.push_back({st, end});
                    inserted = true;
                }

                ans.push_back({s, e});
            }
        }

        // newInterval hasn't been inserted yet
        if (!inserted) {
            ans.push_back({st, end});
        }

        return ans;
    }
};