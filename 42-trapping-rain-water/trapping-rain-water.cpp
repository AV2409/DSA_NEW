class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int n = height.size();
        int prevM = 0;
        int nextM = 0;
        int ans = 0;

        vector<int>prevMaxi(n);
        vector<int>nextMaxi(n);
        int prev=height[0];
        for(int i=1;i<n;i++){
            prevMaxi[i]=prev;
            prev=max(height[i],prev);
        }

        int next=height[n-1];
        for(int i=n-2;i>=0;i--){
            nextMaxi[i]=next;
            next=max(height[i],next);
        }

        for(int i=0;i<n;i++){
            int mini=min(prevMaxi[i],nextMaxi[i]);
            // if(mini==-1) continue;
            ans+=max(0,mini-height[i]);
        }


        return ans;
    }
};