#ifndef INDEX_H
#define INDEX_H
#include "dsvector.h"

using namespace std;

class Index
{
private:
    string s;
    DSVector<string> pages;

public:
    Index();
    string getWord() {return s;}
    void setString(string strIn);
    void checkPage(string p);


};

#endif // INDEX_H
