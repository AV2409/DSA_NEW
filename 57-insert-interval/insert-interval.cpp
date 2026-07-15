class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {

        vector<vector<int>> ans;
        int s = newInterval[0];
        int e = newInterval[1];
        bool inserted = false;
        for (auto &it : intervals) {
            // current interval completely before new interval
            if (it[1] < s) {
                ans.push_back(it);
            }
            // current interval completely after new interval
            else if (it[0] > e) {
                if (!inserted) {
                    ans.push_back({s, e});
                    inserted = true;
                }
                ans.push_back(it);
            }
            // overlap
            else {
                s = min(s, it[0]);
                e = max(e, it[1]);
            }
        }

        if (!inserted)
            ans.push_back({s, e});

        return ans;
    }
};