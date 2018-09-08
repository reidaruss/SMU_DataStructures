#ifndef TWEET_H
#define TWEET_H
#include <vector>
#include <string>

using namespace std;

class Tweet
{
private:
    int id;
    string username;
    bool sent;
    //vector <Word> tweet;

public:
    Tweet();
    //Tweet(int id, string usrName, Word tweet, int sent);

    //void parseTweet(vector<Word> raw);
    bool setSent(int sent);
};

#endif // TWEET_H
