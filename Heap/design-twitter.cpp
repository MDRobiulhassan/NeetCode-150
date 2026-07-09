#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follower;
    int time = 0;

    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        follower[userId].insert(userId);

        priority_queue<pair<int, int>> pq;

        for (int followeeId : follower[userId])
        {
            for (auto &tweet : tweets[followeeId])
            {
                pq.push(tweet);
            }
        }

        vector<int> res;

        while (!pq.empty() && res.size() < 10)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId)
    {
        follower[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            follower[followerId].erase(followeeId);
    }
};