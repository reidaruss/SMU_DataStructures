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
    int getPagesSize() {return pages.getSize();}
    DSVector<string> returnPages(){return pages;}
    void setString(const string strIn);
    void checkPage(const string p);
    void print();

    bool operator<(const Index &i2);



};

#endif // INDEX_H
