#include "tweet.h"
//#include "word.h"



Tweet::Tweet(int id, int sentiment, vector<Word> t)
{
    this->id = id;

    this->sent = false;
}




bool setSent(int sent)    //set the sentiment to true if 4 and false if 0.
{
    if(sent == 0)
        return false;
    else if(sent == 4)
        return true;

}

