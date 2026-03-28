class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        sort(stations.begin(), stations.end());
        if (target <= startFuel)
            return 0;
        int n = stations.size();
        priority_queue<int> pq;
        int dist = startFuel;
        int idx = 0;
        int ans = 0;
        while (idx < n && stations[idx][0] <= dist) {
            pq.push(stations[idx][1]);
            idx++;
        }

        while (!pq.empty()) {
            int fuel = pq.top();
            pq.pop();
            dist += fuel;
            ans++;
            if (dist >= target)
                return ans;
            while (idx < n && stations[idx][0] <= dist) {
                pq.push(stations[idx][1]);
                idx++;
            }
        }
        return -1;
    }
};