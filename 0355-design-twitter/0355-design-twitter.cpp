class Twitter {
public:
    struct Tweet {
        int tweetId;
        int timestamp;
        Tweet(int tweetId, int timestamp): tweetId(tweetId), timestamp(timestamp) {}
    };

    class MyComparator {
    public:
        bool operator() (const Tweet* tweet1, const Tweet* tweet2) {
            return tweet1->timestamp < tweet2->timestamp;
        }
    };

    unordered_map<int, vector<Tweet*>> userTweets;
    unordered_map<int, unordered_set<int>> userFollowings;
    int counter = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        Tweet* tweet = new Tweet(tweetId, counter);
        counter++;

        if (userTweets.count(userId)) {
            if (userTweets[userId].size() == 10) {
                userTweets[userId].erase(userTweets[userId].begin());
                userTweets[userId].push_back(tweet);
            } else {
                userTweets[userId].push_back(tweet);
            }
        } else {
            userTweets[userId].push_back(tweet);
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet*, vector<Tweet*>, MyComparator> tweets;
        unordered_set<int> followers = userFollowings[userId];
        for (auto it = followers.begin(); it != followers.end(); it++) {
            for (Tweet* tweet : userTweets[*it]) {
                tweets.push(tweet);
            }
        }
        for (Tweet* tweet : userTweets[userId]) {
            tweets.push(tweet);
        }
        int count = 0;
        vector<int> res;
        while (count < 10 && !tweets.empty()) {
            Tweet* tweet = tweets.top(); tweets.pop();
            res.push_back(tweet->tweetId);
            count++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowings[followerId].erase(followeeId);
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