#include "tweet.h"
//#include "word.h"


//Tweet::Tweet(int id, std::string usrName, Word tweet, int sent)
//{
//    this->id = id;
//    this-> username = usrName;
//    //this->tweet = tweet;
//    this->sent = false;
//}


void parseTweet(vector<string> raw)
{

}


bool setSent(int sent)    //set the sentiment to true if 4 and false if 0.
{
    if(sent == 0)
        return false;
    else if(sent == 4)
        return true;

}

