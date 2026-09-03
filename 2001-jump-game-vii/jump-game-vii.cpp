class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();

        int maxi=0;
        int curr=0;

        queue<int>q;
        q.push(0);
        vector<int>vis(n);
        int farthest=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            int l=max(curr+minJump,farthest);
            int r=min(curr+maxJump,n-1);

            for(int i=l;i<=r;i++){
                if(!vis[i] && s[i]=='0') {
                    q.push(i);
                    vis[i]=1;
                }
            }
            if(vis[n-1]) return true;
            farthest=r;
        }
        return false;
    }
};