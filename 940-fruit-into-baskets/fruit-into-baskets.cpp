class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int n=fruits.size();
        unordered_map<int,int>hash;
        int cnt=0;
        int ans=0;
        for(int r=0;r<n;r++){
            if(hash[fruits[r]]++==0) cnt++;

            while(cnt>2){
                if(--hash[fruits[l]]==0) cnt--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};