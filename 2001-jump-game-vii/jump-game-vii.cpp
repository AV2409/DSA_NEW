class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1') return false;

        queue<int>q;
        q.push(0);
        vector<int>vis(n);
        int farthest=0;
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            if(idx==n-1) return true;
            int mini=max(farthest,idx+minJump);
            int maxi=min(idx+maxJump,n-1);

            for(int i=mini;i<=maxi;i++){
                if(s[i]=='0' && !vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
            farthest=maxi;
        }
        return false;
    }
};