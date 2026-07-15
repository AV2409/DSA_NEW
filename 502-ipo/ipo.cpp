class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int,int>>tasks;
        int n = profits.size();
        for (int i = 0; i < n; i++) {
            tasks.push_back({capital[i],profits[i]});
        }

        sort(tasks.begin(),tasks.end());
        int idx=0;
        for(int i=0;i<k;i++){
            while(idx<n && tasks[idx].first<=w){
                pq.push(tasks[idx].second);
                idx++;
            }

            if(pq.empty()) break;

            int maxPro=pq.top();
            pq.pop();
            w+=maxPro;
        }

        return w;
    }
};