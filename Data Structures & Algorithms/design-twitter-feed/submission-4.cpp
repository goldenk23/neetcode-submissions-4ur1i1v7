class Twitter {
public:
int timestamp;
unordered_map<int,vector<pair<int,int>>>feed;
unordered_map<int,set<int>>following;
    Twitter() {
        timestamp=0;   
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
            feed[userId].push_back({timestamp,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>max_heap;
      for(int i=feed[userId].size()-1,pushed=0;i>=0&&(pushed<10);i--,pushed++){
        max_heap.push(feed[userId][i]);
      }
      for(auto it:following[userId]){
        for(int i=feed[it].size()-1,pushed=0;i>=0&&(pushed<10);i--,pushed++){
            max_heap.push(feed[it][i]);
        }
      }
        vector<int>News;
        int count=0;
        while(!max_heap.empty()&&count<10){
            News.push_back(max_heap.top().second);
            max_heap.pop();
            count++;
        }
        return News;  
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            following[followerId].insert(followeeId);   
        } 
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].
        erase(followeeId);
    }
};
