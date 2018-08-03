/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
class Compare
{
    public:
        bool operator() (Tweet t1, Tweet t2)
        {
            return t1.id > t2.id;
        }
};

class MiniTwitter {
public:
    unordered_map<int,vector<Tweet>> tweetMap;
    unordered_map<int,vector<int>> followerMap;
    
    MiniTwitter() {
        // do intialization if necessary
        
    }

    /*
     * @param user_id: An integer
     * @param tweet_text: a string
     * @return: a tweet
     */
     Tweet postTweet(int user_id, string &tweet_text) {
        // write your code here
        Tweet new_tweet = Tweet::create(user_id, tweet_text);
        if(tweetMap.find(user_id) == tweetMap.end())
        {
            vector<Tweet> tweets;
            tweetMap[user_id] = tweets;
        }
        tweetMap[user_id].insert(tweetMap[user_id].begin(),new_tweet);
        //if(tweetMap[user_id].size() > 10)
        //    tweetMap[user_id].pop_back();
        if(followerMap.find(user_id) == followerMap.end())
            follow(user_id, user_id);
        return new_tweet;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new feeds recently and sort by timeline
     */
    vector<Tweet> getNewsFeed(int user_id) {
        // write your code here
        vector<Tweet> ret;
        if(followerMap.find(user_id) == followerMap.end())
            return vector<Tweet>();
        vector<int> followers = followerMap[user_id];
        priority_queue<Tweet, std::vector<Tweet>, Compare> pq;
        for(int id: followers)
        {
            if(tweetMap.find(id) == tweetMap.end())
                continue;
            for(Tweet tweet:tweetMap[id])
            {
                pq.push(tweet);
                if(pq.size() > 10)
                    pq.pop();
            }
        }
        while(!pq.empty())
        {
            ret.insert(ret.begin(),pq.top());
            pq.pop();
        }
        return ret;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new posts recently and sort by timeline
     */
    vector<Tweet> getTimeline(int user_id) {
        // write your code here
        if(tweetMap.find(user_id) == tweetMap.end())
            return vector<Tweet>();
        return tweetMap[user_id];
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int from_user_id, int to_user_id) {
        // write your code here
        
        if(followerMap.find(from_user_id) == followerMap.end())
            followerMap[from_user_id] = vector<int>();
        
        vector<int>::iterator result = find(followerMap[from_user_id].begin(),followerMap[from_user_id].end(), to_user_id);
        if(result != followerMap[from_user_id].end())
            return;
        followerMap[from_user_id].push_back(to_user_id);
        return;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int from_user_id, int to_user_id) {
        // write your code here
        if(followerMap.find(from_user_id) == followerMap.end())
            followerMap[from_user_id] = vector<int>();
        vector<int>::iterator result = find(followerMap[from_user_id].begin(),followerMap[from_user_id].end(), to_user_id);
        if(result == followerMap[from_user_id].end())
            return;
        vector<int>::iterator iter1 = followerMap[from_user_id].begin();
        for(iter1;iter1 != followerMap[from_user_id].end(); ++iter1)
        {
            if(*iter1 == to_user_id)
                break;
        }
        followerMap[from_user_id].erase(iter1);
        return;
    }
};
