class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>mp;
        for(int x:hand){
            mp[x]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.first,it.second});
        }

        while(!pq.empty()){
            auto [card,cnt]=pq.top();
            pq.pop();
            queue<pair<int,int>>q;
            for(int i=1;i<=groupSize-1;i++){
                if(pq.empty()) return false;
                auto [c1,cnt2]=pq.top();
                pq.pop();
                if(c1!=card-i) return false;
                if(cnt2<cnt) return false;
                cnt2-=cnt;
                if(cnt2) q.push({c1,cnt2});
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
        return true;
    }
};