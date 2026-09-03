class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<vector<int>> v;
        int n = profits.size();
        for (int i = 0; i < n; i++) {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        //{profit,cap,idx}
        priority_queue<tuple<int, int, int>> pq;
        int idx = 0;
        while (idx < n && v[idx][0] <= w) {
            pq.push({v[idx][1], v[idx][0], idx});
            idx++;
        }
        int ans = w;
        while (k-- && !pq.empty()) {
            auto [pro, cap, i] = pq.top();
            pq.pop();
            ans += pro;

            while (idx < n && v[idx][0] <= ans) {
                pq.push({v[idx][1], v[idx][0], idx});
                idx++;
            }
        }
        return ans;
    }
};