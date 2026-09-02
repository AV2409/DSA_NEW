class Solution {
public:
    bool isPossible(int mid,vector<int>& citations){
        int ans=0;
        for(int x:citations){
            if(x>=mid) ans++;
        }
        return ans>=mid;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int ans=0;
        int l=0;
        int h=n;
        while(l<=h){
            int mid=(l+h)/2;
            if(isPossible(mid,citations)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};