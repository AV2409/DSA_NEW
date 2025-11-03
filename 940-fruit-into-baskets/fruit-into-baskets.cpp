class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> mp;

        int l=0;
        int r=0;
        int unq_cnt=0;
        int res=0;

        while(r<n){
            if(mp[fruits[r]]==0) unq_cnt++;
            mp[fruits[r]]++;

            if(unq_cnt>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) unq_cnt--;
                l++;
            }

            if(unq_cnt<=2) res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};