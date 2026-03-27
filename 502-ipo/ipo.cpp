class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        priority_queue<pair<int, int>> max_pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            min_pq;
        int n = profits.size();
        int ans = w;
        int tasks = 0;
        for (int i = 0; i < n; i++) {
            min_pq.push({capital[i], profits[i]});
        }

        while (!min_pq.empty() && min_pq.top().first <= ans) {
            int cap = min_pq.top().first;
            int pro = min_pq.top().second;
            max_pq.push({pro, cap});
            min_pq.pop();
        }

        while (!max_pq.empty()) {
            int c = max_pq.top().second;
            int p = max_pq.top().first;
            ans += p;
            tasks++;
            max_pq.pop();
            if(tasks==k) return ans;
            while (!min_pq.empty() && min_pq.top().first <= ans) {
                int cap = min_pq.top().first;
                int pro = min_pq.top().second;
                max_pq.push({pro, cap});
                min_pq.pop();
            }
        }
        return ans;
    }
};