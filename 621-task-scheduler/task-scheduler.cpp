class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> mp;
        for (char c : tasks)
            mp[c]++;
        priority_queue<int> pq;
        for (auto it : mp) {
            pq.push(it.second);
        }

        int ans = 0;

        while (!pq.empty()) {
            queue<int> q;
            for (int i = 0; i <= n; i++) {
                if (pq.empty()) {
                    if (!q.empty())
                        ans+=n-i+1;
                    break;
                }
                int x = pq.top();
                pq.pop();
                x--;
                ans++;
                if (x > 0)
                    q.push(x);
            }
            while (!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};