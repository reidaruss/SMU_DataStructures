#include "output.h"
#include <fstream>
#include <iostream>
#include <string.h>



using namespace std;

Output::Output()
{

}

void Output::sortWords(const DSVector<Index>& v)
{
//    string temp;
//    for(int i = 1; i < v.getSize(); i ++)
//    {
//        for(int j = 1; j < v.getSize(); j++)
//        {
//            if(strcmp(v[j-1].getWord(),v[j].getWord()),>0)
//            {
//                strcpy(temp, v[j-1].getWord());
//                v[j-1].setString(v[j].getWord());
//                v[j].setString(temp);
//            }
//        }
//    }

}

void Output::writeOut(char* argv[])
{
    ofstream fout(argv[3]); //create output stream object
    if(fout.is_open())
    {

    }
    else
        cout << "Error in file output" << endl;

}
