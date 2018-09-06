#ifndef TWEET_H
#define TWEET_H
#include "word.h"
#include <vector>
#include <string>

class Tweet
{
private:
    int id;
    std::string username;
    bool sent;
    std::vector <Word> tweet;

public:
    Tweet();
    Tweet(int id, std::string usrName, Word tweet, int sent);

    std::string getUsr();
    bool setSent(int sent);
};

#endif // TWEET_H
