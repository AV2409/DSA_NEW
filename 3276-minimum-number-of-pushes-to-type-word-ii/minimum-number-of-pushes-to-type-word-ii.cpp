class Solution {
public:
    int minimumPushes(string word) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mp;
        for(char c:word){
            mp[c]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        int ans=0;
        int x=1;

        while(!pq.empty()){
            for(int i=1;i<=8;i++){
                if(pq.empty()) break;
                auto node=pq.top();
                pq.pop();
                int cnt=node.first;
                ans+=cnt*x;
            }
            x++;
        }
        return ans;

    }
};