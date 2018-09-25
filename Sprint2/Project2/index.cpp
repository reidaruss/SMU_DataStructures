#include "index.h"
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include "dsvector.h"

using namespace std;


Index::Index()
{
    s = "";


}

void Index::setString(const string strIn)
{
    s = strIn;
}

void Index::checkPage(const string p) //check if page is already in the vector of pages, if not add it
{
    bool in = false;
    for(int i =0; i < pages.getSize(); i++)
        if(pages[i] == p)
            in = true;

    if(in == false)
        pages.pushBack(p);

}

void Index::print()
{
    cout << "[" << s.at(0) << "]" << endl;
    cout << s << ": " ;
    for(int i = 0; i < pages.getSize(); i ++)
    {
        if(i < pages.getSize() -1)
            cout << pages[i] << ", ";
        else if(i == pages.getSize()-1)
            cout << pages[i] << endl;
    }
}

bool Index::operator <(const Index &i2)
{
    return this->getWord() < i2.s;
}








