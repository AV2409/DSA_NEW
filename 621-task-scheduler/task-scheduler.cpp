class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();
        unordered_map<char, int> mp;
        for (char ch : tasks) {
            mp[ch]++;
        }
        priority_queue<int> pq;
        stack<int> st;

        for (auto it : mp) {
            pq.push(it.second);
        }

        int cnt = 0;
        while (!pq.empty()) {
            int temp = pq.top();
            pq.pop();
            cnt++;
            if (temp - 1 > 0)
                st.push(temp - 1);
            int x = n;
            while (!pq.empty() && x--) {
                int tt = pq.top();
                pq.pop();
                cnt++;
                if (tt - 1 > 0) {
                    st.push(tt - 1);
                }
            }
            while (!st.empty()) {
                pq.push(st.top());
                st.pop();
            }

            if (!pq.empty()&&x>0)
                cnt += x;
        }
        return cnt;
    }
};
