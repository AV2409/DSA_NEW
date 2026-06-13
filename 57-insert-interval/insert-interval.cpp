class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;

        int newSt = newInterval[0];
        int newEnd = newInterval[1];

        bool inserted = false;

        for(auto &it : intervals) {

            if(it[1] < newSt) {
                ans.push_back(it);
            }
            else if(it[0] > newEnd) {

                if(!inserted) {
                    ans.push_back({newSt, newEnd});
                    inserted = true;
                }

                ans.push_back(it);
            }
            else {
                newSt = min(newSt, it[0]);
                newEnd = max(newEnd, it[1]);
            }
        }

        if(!inserted)
            ans.push_back({newSt, newEnd});

        return ans;
    }
};