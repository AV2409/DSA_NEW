class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int ans=0;
        vector<int> hash(26, 0);
        for (char c : tasks) {
            hash[c - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if(hash[i]>0)
                pq.push(hash[i]);
        }

        while (!pq.empty()) {
            auto cnt1 = pq.top();
            pq.pop();
            ans++;
            cnt1--;
            queue<int>q;
            if (cnt1 > 0) {
                for(int i=0;i<n;i++){
                    ans++;
                    if(pq.empty()) continue;
                    auto cnt2 = pq.top();
                    pq.pop();
                    cnt2--;
                    if(cnt2>0) q.push(cnt2);
                }
                while(!q.empty()){
                    pq.push(q.front());
                    q.pop();
                }
                pq.push(cnt1);
            }

        }
        return ans;
    }
};