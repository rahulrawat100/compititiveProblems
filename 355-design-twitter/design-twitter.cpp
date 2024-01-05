class Twitter {
public:
    vector<set<int>> follows;
    vector<vector<int>> tweets;
    unordered_map<int, int> Dap;
    int time=0;
    Twitter() {
        vector<int> D;
        set<int> E;
        for(int i=0; i<500; i++)
        {
            follows.push_back(E);
            tweets.push_back(D);
        }
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(time);
        Dap[time]=tweetId;
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> pos;
        int s=tweets[userId].size();
        if(s>0)
           pq.push({tweets[userId][s-1], userId});
        pos[userId]=s-1;
        for(auto id:follows[userId])
        {
            int s=tweets[id].size();
           if(s>0)
             { 
              pq.push({tweets[id][s-1], id});
              pos[id]=s-1;
             }
        }
        vector<int> res;
        while(!pq.empty()&&res.size()<10)
        {
            int tid = pq.top().first;
            int uid = pq.top().second;
            pq.pop();
            res.push_back(Dap[tid]);
            if(pos[uid]>0)
            {
                pos[uid]--;
                pq.push({tweets[uid][pos[uid]], uid});
            }
        }
        return res;
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