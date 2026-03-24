class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();

        int i = 0;
        int j = 0;
        vector<vector<int>> ans;
        while (i < n && j < m) {
            int st1 = firstList[i][0];
            int end1 = firstList[i][1];

            int st2 = secondList[j][0];
            int end2 = secondList[j][1];
            int start = max(st1, st2);
            int end = min(end1, end2);
            if (start<=end) {
                ans.push_back({start, end});
            } 

            if(end1<end2) i++;
            else j++;
        }
        return ans;
    }
};