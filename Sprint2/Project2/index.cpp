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


}

void Index::setString(string strIn)
{
    s = strIn;
}

void Index::checkPage(string p) //check if page is already in the vector of pages, if not add it
{
    bool in = false;
    for(int i =0; i < pages.getSize(); i++)
        if(pages[i] == p)
            in = true;

    if(in == false)
        pages.pushBack(p);

}








