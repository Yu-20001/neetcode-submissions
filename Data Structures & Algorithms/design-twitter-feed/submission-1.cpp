class Twitter {
private:
    vector<vector<int>> tweetPool;
    vector<vector<int>> followeeList;
    unordered_map<int, unordered_set<int>> followMap;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetPool.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int cnt = 0;
        unordered_set<int> followee = followMap[userId];
        followee.insert(userId);
        int pid = !tweetPool.empty() ? tweetPool.size() - 1 : 0;
        while(pid >= 0 && cnt < 10){
            int uid = tweetPool[pid][0];
            for(int person : followee){
                if(uid == person){
                    feed.push_back(tweetPool[pid][1]);
                    cnt++;
                    break;
                }
            }
            pid--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
