#ifndef USER_H
#define USER_H
#include <string>
#include "tweet.h"
#include <vector>


class User
{
private:
    string username;
    vector<Tweet> tweets;
public:
    User();
    User(string usrName, vector<string> t);
};

#endif // USER_H
