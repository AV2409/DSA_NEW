class Solution {
public:
    // static bool comp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> ans;
        long long timer = INT_MAX;
        int i=0;
        for (auto& v : tasks) {
            v.push_back(i);
            i++;
            timer = min(timer, 1LL*v[0]);
        }
        sort(tasks.begin(), tasks.end());
        //{bt,i}
        priority_queue<tuple<int, int>,vector<tuple<int, int>>,greater<tuple<int, int>>> pq;
        int idx = 0;
        while (idx < n && tasks[idx][0] <= timer) {
            pq.push({tasks[idx][1], tasks[idx][2]});
            idx++;
        }

        while (ans.size() != n) {
            if (pq.empty()) {
                timer = tasks[idx][0];
                while (idx < n && tasks[idx][0] <= timer) {
                    pq.push({tasks[idx][1], tasks[idx][2]});
                    idx++;
                }
                continue;
            }
            auto [bt, i] = pq.top();
            ans.push_back(i);
            pq.pop();
            timer += bt;

            while (idx < n && tasks[idx][0] <= timer) {
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }
        }
        return ans;
    }
};