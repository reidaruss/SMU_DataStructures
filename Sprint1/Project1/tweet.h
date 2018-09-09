#ifndef TWEET_H
#define TWEET_H
#include <vector>
#include <string>
#include "word.h"

using namespace std;

class Tweet
{
private:
    int id;
    string username;
    bool sent;
    vector <Word> tweet;

public:
    Tweet();
    Tweet(int id, string usrName, int sentiment, vector<Word> t);

    bool setSent(int sent);
};

#endif // TWEET_H
