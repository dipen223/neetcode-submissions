class Twitter {
public:
    int timestamp = 0;
    unordered_map<int,vector<pair<int,int>>>posts;
    unordered_map<int,set<int>>followList;  
                                            
    Twitter() {
        
    }

    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> maxHeap;
        followList[userId].insert(userId);

        for(int followeeId:followList[userId]){
            auto &tweets = posts[followeeId];
            int n = tweets.size();

            for(int i=max(0,n-10); i<n; i++){
                maxHeap.push(tweets[i]);
            }
        }

        vector<int> result;
        while (!maxHeap.empty() && result.size() < 10) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
        
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followList[followerId].erase(followeeId);

        }
        
    }
};
