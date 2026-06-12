class Twitter {
public:
    vector<unordered_set<int>>follows;
    vector<vector<pair<int,int>>>tweets; //id,timer
    int timer;
    Twitter() {
        follows.resize(501);
        tweets.resize(501);
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId,timer});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        unordered_set<int> users=follows[userId];
        users.insert(userId);
        vector<int>feed;
        for(int id:users){
            for(auto it:tweets[id]){
                int tid=it.first;
                int time=it.second;

                pq.push({time,tid});
                if(pq.size()>10) pq.pop();
            }
        }
        while(!pq.empty()){
            feed.push_back(pq.top().second);
            pq.pop();
        }
        reverse(feed.begin(),feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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