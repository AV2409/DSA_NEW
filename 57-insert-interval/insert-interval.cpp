class Solution {
public:
    
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> i1;
        if (n == 0) {
            i1.push_back(newInterval);
            return i1;
        }
        int ns = newInterval[0];
        int ne = newInterval[1];

        int i = 0;

        while (i < n) {
            if (intervals[i][0] < ns) {
                i1.push_back(intervals[i]);
                i++;
            } else {
                i1.push_back(newInterval);
                break;
            }
        }
        if (i == n) {
            i1.push_back(newInterval);
        }

        while (i < n) {
            i1.push_back(intervals[i]);
            i++;
        }

        n = i1.size();
        if (n == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());

        i = 0;
        int j = 1;

        vector<vector<int>> ans;
        int st1 = i1[i][0];
        int end1 = i1[i][1];

        while (j < n) {
            int st2 = i1[j][0];
            int end2 = i1[j][1];
            if (end1 < st2) {
                ans.push_back({st1, end1});
                st1 = st2;
                end1 = end2;
            } else {
                end1 = max(end1, end2);
            }
            j++;
        }

        ans.push_back({st1, end1});
        return ans;
    }
};