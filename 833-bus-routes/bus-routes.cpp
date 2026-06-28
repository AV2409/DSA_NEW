class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        int buses = routes.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < buses; i++) {
            for (int stop : routes[i]) {
                mp[stop].push_back(i);
            }
        }
        vector<bool> vis(buses, false);
        queue<int> q;
        q.push(source);
        unordered_set<int> visStop;
        visStop.insert(source);
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int stop = q.front();
                q.pop();

                if (stop == target)
                    return ans;
                for (int bus : mp[stop]) {
                    if (vis[bus])
                        continue;
                    vis[bus] = true;

                    for (int nextStop : routes[bus]) {

                        if (!visStop.count(nextStop)) {
                            visStop.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
    
};