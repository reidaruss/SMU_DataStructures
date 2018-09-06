#include "tweet.h"
#include "word.h"

Tweet::Tweet(int id, std::string usrName, Word tweet, int sent)
{
    this->id = id;
    this-> username = usrName;
    this->tweet = tweet;
    this->sent = setSent(sent);
}

Tweet::getUsr()
{
    return this->username;
}

Tweet::setSent(int sent)    //set the sentiment to true if 4 and false if 0.
{
    if(sent == 0)
        return false;
    else if(sent == 4)
        return true;
    else
        cerr << "Error setting sentiment. Value passed != 0 or 4." << endl;

}
