class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        sort(stations.begin(), stations.end());
        if (target <= startFuel)
            return 0;
        int n = stations.size();
        priority_queue<pair<int, int>> pq;
        int dist = startFuel;
        int idx = 0;
        int ans = 0;
        while (idx < n && stations[idx][0] <= dist) {
            pq.push({stations[idx][1], stations[idx][0]});
            idx++;
        }

        if (pq.empty())
            return -1;

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            int fuel = temp.first;
            dist += fuel;
            ans++;
            if (dist >= target)
                return ans;
            while (idx < n && stations[idx][0] <= dist) {
                pq.push({stations[idx][1], stations[idx][0]});
                idx++;
            }
        }
        return -1;
    }
};