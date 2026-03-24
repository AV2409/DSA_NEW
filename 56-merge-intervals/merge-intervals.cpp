class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());

        int i = 0;
        int j = 1;

        vector<vector<int>> ans;
        int st1 = intervals[i][0];
        int end1 = intervals[i][1];

        while (j < n) {
            int st2 = intervals[j][0];
            int end2 = intervals[j][1];
            if (end1 < st2) {
                ans.push_back({st1, end1});
                st1 = st2;
                end1 = end2;
            } else {
                end1 = max(end1, end2);
            }
            j++;
        }

        ans.push_back({st1,end1});
        return ans;
    }
};