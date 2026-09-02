class Solution {
public:
    int find(vector<int>& citations,int i){
        int ans=0;
        for(int x:citations){
            if(x>=i) ans++;
        }
        return ans;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int ans=0;
        for(int i=i;i<=n;i++){
            int cnt=find(citations,i);
            if(cnt>=i) ans=i;
        }
        return ans;
    }
};