class Solution {
public:
    int minLights(vector<int>& lights) {
        
        int n=lights.size();
        vector<bool>ilu(n,false);
        int l=0;
        while(l<n){
            int r=l;
            if(lights[r]==0){
                l++;
                continue;
            }

            int x=r+lights[r];

            while(r<=min(n-1,x)){
                ilu[r]=true;
                if(lights[r]) x=max(x,r+lights[r]);
                r++;
            }
            l=r;
        }

        l=n-1;
        while(l>=0){
            int r=l;
            if(lights[r]==0){
                l--;
                continue;
            }

            int x=r-lights[r];

            while(r>=max(0,x)){
                ilu[r]=true;
                if(lights[r]) x=min(x,r-lights[r]);
                r--;
            }
            l=r;
        }
        l=0;
        
        int ans=0;
        while(l<n){
            int r=l;
            int cnt=0;
            if(ilu[l]){
                l++;
                continue;
            }
            while(r<n && cnt<3 && !ilu[r]){
                cnt++;
                r++;
            }
            l=r;
            ans++;
        }
        // for(int i=0;i<n;i++){
        //     cout<<ilu[i]<<" ";
        // }
        return ans;
    }
};