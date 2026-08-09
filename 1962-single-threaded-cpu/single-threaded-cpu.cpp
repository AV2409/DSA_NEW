class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int i = 0;
        int n = tasks.size();
        for (auto& t : tasks) {
            t.push_back(i);
            i++;
        }
        sort(tasks.begin(), tasks.end(), comp);
        int idx = 0;
        long long timer = tasks[0][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        while (idx < n && tasks[idx][0] <= timer) {
            pq.push({tasks[idx][1], tasks[idx][2]});
            idx++;
        }
        vector<int>ans;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int proTime = it.first;
            int ii = it.second;
            ans.push_back(ii);
            timer += proTime;
            if(idx<n && pq.empty()) timer=max(timer,1LL*tasks[idx][0]);
            while (idx < n && tasks[idx][0] <= timer) {
                pq.push({tasks[idx][1], tasks[idx][2]});
                idx++;
            }
        }
        return ans;
    }
};