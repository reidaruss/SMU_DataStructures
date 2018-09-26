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
    s = strIn;      //set word
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

string Index::returnPages()
{
    string pgstr;
    for(int i = 0; i < pages.getSize(); i ++)       //add the pages into a string ready to be written out
    {
        if(i < pages.getSize() -1)
            pgstr += pages[i] + ", ";
        else if(i == pages.getSize()-1)
            pgstr += pages[i];
    }

    return pgstr;

}

char Index::getFE()
{
    return s.at(0);     //return first character in the word, used in output
}



bool Index::operator <(const Index &i2)
{
    return this->getWord() < i2.s;
}








