class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        priority_queue<pair<int, pair<int, int>>> pq;
        for (auto& point : points) {
            int x = point[0];
            int y = point[1];
            int dist = x * x + y * y;

            pq.push({dist, {x, y}});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            auto point = pq.top().second;

            ans.push_back({point.first, point.second});
            pq.pop();
        }
        return ans;
    }
};