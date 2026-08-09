class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>>tasks;
        int n = profits.size();
        for(int i=0;i<n;i++){
            tasks.push_back({capital[i],profits[i]});
        }
        
        sort(tasks.begin(), tasks.end(), comp);
        int idx = 0;
        priority_queue<int>pq;

        while (idx < n && tasks[idx][0] <= w) {
            pq.push(tasks[idx][1]);
            idx++;
        }
        int ans=w;
        while (!pq.empty() && k>0) {
            auto pro = pq.top();
            pq.pop();
            k--;
            ans+=pro;
            w+=pro;
            while (idx < n && tasks[idx][0] <= w) {
                pq.push(tasks[idx][1]);
                idx++;
            }
        }
        return ans;
    }
};