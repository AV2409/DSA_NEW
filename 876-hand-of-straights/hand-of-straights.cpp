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
        
        for(auto it:mp){
            pq.push({it.first,it.second});
        }
        while (!pq.empty()) {
            int card = pq.top().first;
            int cnt = pq.top().second;
            cnt--;
            queue<pair<int,int>>q;
            if(cnt>0) q.push({card,cnt});
            pq.pop();
            int prev = card;
            for (int i = 1; i < groupSize; i++) {
                if(pq.empty()) return false;
                int nextCard = pq.top().first;
                if(nextCard!=prev+1) return false;
                int nextCnt = pq.top().second;
                nextCnt--;
                pq.pop();
                if(nextCnt>0) q.push({nextCard,nextCnt});
                prev=nextCard;
            }

            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
        }
        return true;
    }
};