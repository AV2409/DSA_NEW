class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            int x=i-1;
            int y=i+1;
            while(x>=0 && arr[x]<arr[x+1]) x--;
            while(y<n && arr[y]<arr[y-1]) y++;

            left[i]=i-x;
            right[i]=y-i;

            if(left[i]>1 && right[i]>1){
                ans=max(ans,left[i]+right[i]-1);
            }
        }
        for(int i=0;i<n;i++){
            cout<<left[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<right[i]<<" ";
        }
        return ans;
        
    }
};