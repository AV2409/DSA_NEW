class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26);
        for (char c : tasks)
            hash[c-'A']++;
        
        int cnt=0;
        int maxi=1;
        int tot=0;
        for (int it : hash) {
            maxi=max(maxi,it);
            if(it) cnt++;
            tot+=it;
        }

        int temp=0;

        for (int it : hash) {
            if(it==maxi) temp++;
        }

        int slotSize=n+1;
        int slots=maxi;
        int ss=tasks.size();
        int ans=(slots-1)*(slotSize);
        ans=max(ss,ans+temp);
        return ans;
    }
};