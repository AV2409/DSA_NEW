class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        priority_queue<pair<int, int>> max_pq;
        int n = profits.size();
        int ans = w;
        int tasks = 0;
        vector<pair<int, int>> gg;
        for (int i = 0; i < n; i++) {
            gg.push_back({capital[i], profits[i]});
        }

        sort(gg.begin(), gg.end());
        int idx=0;
        for (int i = 0; i < k; i++) {

            while (idx<n && gg[idx].first<=ans) {
                int cap = gg[idx].first;
                int pro = gg[idx].second;
                max_pq.push({pro, cap});
                idx++;
            }
            if(max_pq.empty()) return ans;

            int c = max_pq.top().second;
            int p = max_pq.top().first;
            ans += p;
            max_pq.pop();
        }
        return ans;
    }
};