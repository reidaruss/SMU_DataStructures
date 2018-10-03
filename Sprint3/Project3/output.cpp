#include "output.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

Output::Output()
{

}


void Output::writeOut(char* argv[], string *words, int numWords, int numExtract )
{
    ofstream fout(argv[2]); //create output stream object
    if(fout.is_open())
    {


        for(int i = 0; i < numExtract; i++)
        {
            fout << words[i] << endl;
        }

    }
    else
        cout << "Error in file output" << endl;
}
