class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26);
        for(char c:tasks){
            mp[c-'A']++;
        }
        int maxi=*max_element(mp.begin(),mp.end());
        int cnt=0;
        for(int x:mp){
            if(x==maxi) cnt++;
        }

        int x=tasks.size();
        return max(x,(maxi-1)*(n+1)+cnt);
    }
};