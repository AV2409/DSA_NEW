class Twitter {
public:
    int timer;
    unordered_map<int, set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() { timer = 0; }

    void postTweet(int userId, int tweetId) {
        timer++;
        tweets[userId].push_back({timer, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for (auto [time, tweet] : tweets[userId]) {
            pq.push({time, tweet});
            if (pq.size() > 10)
                pq.pop();
        }
        for (int user : following[userId]) {
            for (auto [time, tweet] : tweets[user]) {
                pq.push({time, tweet});
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        int idx=pq.size();
        vector<int> ans(idx);
        idx--;
        while (!pq.empty()) {
            ans[idx]=(pq.top().second);
            pq.pop();
            idx--;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */