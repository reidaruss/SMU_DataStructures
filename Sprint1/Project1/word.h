#ifndef WORD_H
#define WORD_H
#include <string>
//#include "tweet.h"
#include <vector>
using namespace std;


class Word {

private:
    string word;
    string pOS;
public:
    Word();
    Word(string w, string pos);

    //Tweet parseWords(string str);


};

#endif // WORD_H
