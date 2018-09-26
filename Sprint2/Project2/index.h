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
    string returnPages();
    char getFE();
    void setString(const string strIn);
    void checkPage(const string p);
    void print(ofstream &fout);

    bool operator<(const Index &i2);



};

#endif // INDEX_H
