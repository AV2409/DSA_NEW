class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize)
            return false;
        // card,cnt
        unordered_map<int, int> mp;
        for (int x : hand)
            mp[x]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (auto it : mp) {
            pq.push({it.first, it.second});
        }
        while (!pq.empty()) {
            auto [card,cnt]=pq.top();
            pq.pop();
            queue<pair<int,int>>q;
            for(int i=1;i<=groupSize-1;i++){
                if(pq.empty()) return false;
                auto [neiCard,neiCnt]=pq.top();
                pq.pop();

                if(neiCard!=card+i) return false;
                if(neiCnt<cnt) return false;
                neiCnt-=cnt;
                if(neiCnt>0) q.push({neiCard,neiCnt});
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }

        return true;
    }
};