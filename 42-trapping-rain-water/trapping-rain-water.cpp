class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prevM(n);
        vector<int>nextM(n);
        prevM[0]=-1;
        nextM[n-1]=-1;
        int maxi=height[0];
        for(int i=1;i<n;i++){
            prevM[i]=max(maxi,height[i-1]);
            maxi=max(maxi,prevM[i]);
        }
        maxi=height[n-1];

        for(int i=n-2;i>0;i--){
            nextM[i]=max(maxi,height[i+1]);
            maxi=max(maxi,nextM[i]);
        }

        // for(int i=0;i<n;i++){
        //     cout<<prevM[i]<<" ";
        // }
        // cout<<endl;

        // for(int i=0;i<n;i++){
        //     cout<<nextM[i]<<" ";
        // }
        int ans=0;
        for(int i=0;i<n;i++){
            int x=min(prevM[i],nextM[i]);
            ans+=max(0,x-height[i]);
        }
        return ans;

    }
};