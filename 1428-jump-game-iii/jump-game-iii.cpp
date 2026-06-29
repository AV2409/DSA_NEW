class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>vis(n,false);
        vis[start]=true;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            if(arr[idx]==0) return true;

            int next=idx+arr[idx];
            int prev=idx-arr[idx];

            if(next<n && !vis[next]) {
                vis[next]=1;
                q.push(next);
            }

            if(prev>=0 && !vis[prev]) {
                vis[prev]=1;
                q.push(prev);
            }
        }
        return false;
            
    }
};